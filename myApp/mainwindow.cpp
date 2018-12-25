#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());

    QSound::play(":/new/prefix1/welcome.wav");

    // member var initialize: 成员函数初始化
    mTimeCount = 0;
    mPark = new Parkinglot();
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(timerRefresh()));
    mTimer->start(1000);   // 1s 刷新一次

    // 初始化 nowlist View 的一些属性:
    ui->nowlist_table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->nowlist_table->setRowCount(12);
    ui->nowlist_table->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格不可编辑
    ui->waitqueue_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 小汽车 gif 播放
    mStartCarPos = ui->carGraphics->geometry();

    // 设置停车场图片
    displayRemain();

    // 设置logo图片:
    QPixmap logoImg = QPixmap(":/new/prefix1/logo.png").scaled(ui->logo->size());
    ui->logo->setPixmap(logoImg);

    // init ui from data model..
    ui->income->setText(QString::number(mPark->getIncome()));
    ui->remain->setText(QString::number(mPark->getRemain()));
    //this->displayNowlist();

    // about DB..
    initDB();
    bool connect_ok = mDb.open();
      if(connect_ok)  qDebug()<<"Mysql Database connected..";
      else qDebug()<<"Mysql Database connected False..";
    mQuery = QSqlQuery(mDb);


    // 从数据库中加载上一次关闭程序后保存的Cache余留信息:
    QString s = QString("select * from parkingCache ;");
    mQuery.exec(s);
    for(int i=0; mQuery.next(); i++){
        Nowinfo *item = new Nowinfo(nullptr, QString(mQuery.value(0).toString()));
        qDebug()<<"Item cusId: "<< mQuery.value(0);
        // 保存某一条数据中他的进站时间, 用QDateTime类从时间戳转化成时间然后用.secsTo算时间差
        QString itemEntryTime_t = QString(mQuery.value(1).toString());
        qDebug()<<"Item EntryTime: "<< itemEntryTime_t;

        // 获取两个 QDateTime 对象
        QDateTime curTime = QDateTime::currentDateTime();
        QDateTime itemEntryTime = QDateTime::fromString(itemEntryTime_t, "yyyy-MM-dd hh:mm:ss");

        // 计算时间差
        qint64 itemStayTime_d = itemEntryTime.secsTo(curTime);
        qDebug()<< "Time dec: " << itemStayTime_d;
        QString itemStayTime = QString::number(itemStayTime_d);

        // 为了让 Nowinfo *item 的每秒刷新工具正常工作, 还需要将 itemEntryTime_d..
        item->setEn_time_d(itemStayTime_d);
        item->setStay_time(itemStayTime);

        mPark->getNowlist()->append(item);
    }

    // 清楚 parkingCache 缓存, 刷新停车场监控图..
    mQuery.exec("delete from parkingCache ;");
    mPark->setRemain( 12 - mPark->getNowlist()->length() );
    displayRemain();
}

MainWindow::~MainWindow()
{
    delete ui;
    mDb.close();
}

void MainWindow::initDB(){
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        qDebug() << "Using Default connection..";
        mDb.database("qt_sql_default_connection");
    }else {

        mDb = QSqlDatabase::addDatabase("QSQLITE");
        mDb.setDatabaseName("parkingUser.db");
    }
}

void MainWindow::on_refreshBtn_clicked()
{
    /* TODO 实现收入额、余车位刷新功能 */
    qDebug()<<" qdebug: refreshBtn clicked...";
    updateView();
}

bool MainWindow::waitQuestion()
{
    switch(QMessageBox::question(this,"提示","已经没车位啦, 是否进入排队?",
            QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
        case QMessageBox::Ok:
            return true;
        case QMessageBox::Cancel:
            return false;

        default:
            return false;
    }
}

QString MainWindow::swipeMonitor()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         "刷卡模拟",
                                         "请输入你的车牌号:",
                                         QLineEdit::Normal,
                                         "",
                                         &ok);
    if(ok && !name.isEmpty()) {
        return name;
    }else {
        return "false";
    }
}

QString MainWindow::payMonitor()
{
    bool ok;
    QString payment = QInputDialog::getText(this,
                                         "付款模拟",
                                         "请输入你的付款金额(元):",
                                         QLineEdit::Normal,
                                         "",
                                         &ok);
    if(ok && !payment.isEmpty()) {
        return payment;
    }else {
        return "false";
    }
}

void MainWindow::chargeMonitor(QString cusId, double charge)
{
    QMessageBox *qb = new QMessageBox(this);

    if(qb->warning(this,
                    "找零提示" , "付款后仍有剩余, 您是否选择将找零充入停车卡余额?",
                    QMessageBox::Yes ,
                    QMessageBox::Cancel | QMessageBox::Default | QMessageBox::Escape , 0) == QMessageBox::Yes) {
        // 选择将找零充入余额
        QString s = QString("update user set balance = balance + %1 where id= '%2' ;").arg(charge).arg(cusId);
        mQuery.exec(s);
        qDebug()<< "SQLite query: [ "<< s <<" ];";

    }else {
        QMessageBox::about(this, "一路平安", QString("找您 %1 元, 再见,期待您的下次光临。").arg(QString::number(charge, 'f', 2)));
    }
}

void MainWindow::refreshRemainView()
{
    this->ui->remain->setText(QString::number(this->mPark->getRemain()));
}

void MainWindow::refreshIncomeView()
{
    this->ui->income->setText(QString::number(this->mPark->getIncome(), 'f', 2));
}

void MainWindow::displayNowlist()
{
    ui->nowlist_table->setRowCount(0);
    ui->nowlist_table->setRowCount(12);

    /* 将Nowlist 显示到 Nowlist中去 */
    for(int i=0; i<mPark->getNowlist()->length(); i++){
        ui->nowlist_table->setItem(i, 0, new QTableWidgetItem(mPark->getNowlist()->at(i)->getCarId()));
        ui->nowlist_table->setItem(i, 1, new QTableWidgetItem(mPark->getNowlist()->at(i)->getEn_time()));
        ui->nowlist_table->setItem(i, 2, new QTableWidgetItem(mPark->getNowlist()->at(i)->getStay_time()));
        ui->nowlist_table->setItem(i, 3, new QTableWidgetItem(QString::number(mPark->getNowlist()->at(i)->getFee(), 'f', 2)));
    }
}

void MainWindow::displayWaitqueue(){
    ui->waitqueue_table->setRowCount(0);
    int len = mPark->getWq()->length();
    ui->waitqueue_table->setRowCount( len );

    for(int i=0; i<len; i++){
        QString s = mPark->getWq()->at(i)->getPcarId();
        ui->waitqueue_table->setItem(i, 0, new QTableWidgetItem( s )); //todo
        ui->waitqueue_table->setItem(i, 1, new QTableWidgetItem( mPark->getWq()->at(i)->getCurStaytime()));
    }

}

void MainWindow::newUserEntry(QString cusId)
{
    mPark->decRemain();  //　余位-1

    // 动画效果...
    QMovie *carImg = new QMovie(":/new/prefix1/e.gif");
    carImg->setScaledSize(ui->carGraphics->size());
    ui->carGraphics->setMovie(carImg);
    carImg->start();


    ui->carGraphics->setVisible(true);
    QPropertyAnimation *startAnime = new QPropertyAnimation(ui->carGraphics, "geometry");

    // 绑定 动画结束时事件槽函数:
    connect(startAnime, &QPropertyAnimation::finished, [=]{
        ui->carGraphics->setVisible(false);
//          尝试in.gif 失败
//        QMovie *inImg = new QMovie(":/new/prefix1/in.gif");
//        inImg->setScaledSize(ui->pkTwoGraphics->size());
//        inImg->setSpeed(200);
//        ui->pkTwoGraphics->setMovie(inImg);
//        inImg->start();

//        connect(inImg, SIGNAL(QMovie::finished), this, SLOT(exDisplayRemain()));

        refreshRemainView();
        QSound::play(":/new/prefix1/entry.wav");
        // 确认进站动画结束后, 看上去像是真的进站了, 然后刷新在站内车辆列表
        carImg->stop();
        mEndCarPos = ui->carGraphics->geometry();

        Nowinfo* newEntry = new Nowinfo(nullptr, cusId);
        (mPark->getNowlist())->append(newEntry);
        displayRemain();
        displayNowlist();

//        inImg->finished();
    });

    startAnime->setDuration(1300);
    startAnime->setStartValue(mStartCarPos);
    startAnime->setEndValue(QRect(360, 240, 241, 171));
    startAnime->start();

}

void MainWindow::Userleave(QString cusId)
{
    // 翻转图片
    QMovie *carImg = new QMovie(":/new/prefix1/el.gif");
    carImg->setScaledSize(ui->carGraphics->size());
    ui->carGraphics->setMovie(carImg);
    carImg->start();


    mPark->incRemain();  //　余位+1
    displayRemain();

    // 动画效果...
    ui->carGraphics->setVisible(true);
    QPropertyAnimation *leaveAnime = new QPropertyAnimation(ui->carGraphics, "geometry");

    // 绑定 动画结束时事件槽函数:
    connect(leaveAnime, &QPropertyAnimation::finished, [=]{
        ui->carGraphics->setVisible(false);
        refreshRemainView();

        // 确认离开动画结束
        carImg->stop();
        displayNowlist();
    });

    leaveAnime->setDuration(2000);
    leaveAnime->setStartValue(mEndCarPos);
    leaveAnime->setEndValue(mStartCarPos);
    leaveAnime->start();

}

void MainWindow::updateView()
{
    /* 刷新所有视图元素 */
    refreshIncomeView();
    refreshRemainView();
    displayNowlist();
    displayWaitqueue();
}

void MainWindow::displayRemain()
{
    QPixmap parkImg;
    switch (mPark->getRemain()) {
    case 12:
        parkImg = QPixmap(":/new/prefix1/7.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt5.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 11:
        parkImg = QPixmap(":/new/prefix1/7.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt4.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 10:
        parkImg = QPixmap(":/new/prefix1/7.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt3.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 9:
        parkImg = QPixmap(":/new/prefix1/7.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt2.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 8:
        parkImg = QPixmap(":/new/prefix1/7.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt1.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 7:
        parkImg = QPixmap(":/new/prefix1/7.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 6:
        parkImg = QPixmap(":/new/prefix1/6.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 5:
        parkImg = QPixmap(":/new/prefix1/5.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 4:
        parkImg = QPixmap(":/new/prefix1/4.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        break;
    case 3:
        parkImg = QPixmap(":/new/prefix1/3.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 2:
        parkImg = QPixmap(":/new/prefix1/2.png").scaled(561, 291);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 1:
        parkImg = QPixmap(":/new/prefix1/1.png").scaled(561, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    case 0:
        parkImg = QPixmap(":/new/prefix1/0.png").scaled(541, 341);
        ui->parkinglotGraphics->setPixmap(parkImg);
        parkImg = QPixmap(":/new/prefix1/pkt0.png").scaled(381, 281);
        ui->pkTwoGraphics->setPixmap(parkImg);
        break;
    }
}

void MainWindow::on_entryBtn_clicked()
{
    /* 刷卡进站模拟按钮 点击事件 槽函数 */
    QString cusId = swipeMonitor();

    if( cusId != "false" ) {
        /* 检查:是否该车牌号已经入站(健壮性考量) */
        for(int i =0; i<mPark->getNowlist()->length(); i++){
            if(cusId == mPark->getNowlist()->at(i)->getCarId()){
                QMessageBox::critical(this, "Error!", "该车已在站中!");
                return;
            }
        }

        // 如果站内已满, 则弹出 QMessageBox 提示;
        if( mPark->getRemain() == 0 ){
            bool ret = waitQuestion();
            if(ret){
                // 用户选择了排队, 则将该用户添加进 排队队列
                Customer *c = new Customer(nullptr, cusId);
                mPark->getWq()->enqueue(c);

                displayWaitqueue();

            }else{ /* 用户选择了不排队 */
                QSound::play(":/new/prefix1/sorryForNoService.wav");
                QMessageBox::about(this, "一路平安", QString("很遗憾本次为没能为您提供服务, 期待下次再见。"));
            }

        }else{
            /* 弹出一个带输入的Dialog, 输入 个人车牌号以模拟刷卡 */

            if( cusId == "false" ){
                // false 说明用户取消了刷卡(填写卡号)
            }else{
                qDebug()<< "[INFO] 用户Database 查询 [ " << cusId << " ]";
                /* 从用户表数据库中, 通过车牌号pk检索用户 */
                QString s = QString("select count(*), balance from user where id='%1';").arg(cusId);
                if (mQuery.exec(s)) qDebug() << "user Query Execute Success..";
                else qDebug() << " Query Execute Failed.. [ " << mQuery.lastError() << "]";

                while(mQuery.next()){
                    qDebug() << "mQuery.next()..";
                    // 如果返回有结果, 添加进停车场的入站列表
                    if(mQuery.value(0) != 0){
                        // Tips: 入站 要新建一个Nowinfo对象

                        newUserEntry(cusId);
                    }
                    // 如果数据库检测不到该用户, 则视为新用户, 新加注册进数据库:
                    else{
                        QString s = QString("insert into user VALUES('%1', 0.00, 'none', 0);").arg(cusId);
                        qDebug() << "Execute SQL: " << s;
                        if (mQuery.exec(s)) qDebug() << "insert Query Execute Success..";
                        else qDebug() << " Query Execute Failed..[ " << mQuery.lastError() << "]";

                        newUserEntry(cusId);
                    }
                }

            }
        }

    }
    else{
        return; // 模拟刷卡被取消..
    }
}

void MainWindow::timerRefresh()
{
    // 和刷新Btn有重复, 但两功能分属两个槽, 这一部分代码不算冗余。
    // every Second (1s).
    // qDebug()<<"refresh view..";
    updateView();
}

void MainWindow::on_leaveBtn_clicked()
{
    double totalFee = 0;  // 费用结算器变量

    /* 弹出一个带输入的Dialog, 输入 个人车牌号以模拟刷卡 */
    QString cusId = swipeMonitor();
    for(int i=0; i<mPark->getNowlist()->length(); i++){
        // 遍历入站列表, 查找并得到该出站用户的结算费用
        if(mPark->getNowlist()->at(i)->getCarId() == cusId){
            totalFee = mPark->getNowlist()->at(i)->getFee();

            QString s = QString("select balance from user where id='%1' ;").arg(cusId);
            mQuery.exec(s);

            while (mQuery.next()) {
                qDebug() << "mquery hasNext.. ";
                double hisBalance = mQuery.value(0).toDouble();

                // 查询用户卡内余额, 如果余额大于totalFee, 就自动扣费
                // 否则弹出对话框缴纳金额, 如果缴纳金额大于totalFee,
                // 则继续弹出对话框询问是否充入余额内。
                if(hisBalance > totalFee){
                    // 然后从在站内车辆列表中删除
                    mPark->getNowlist()->removeAt(i);
                    QSound::play(":/new/prefix1/PaySuccess.wav");
                    QMessageBox::about(this, "已自动从卡内扣费", "一路平安, 再见！..");
                    qDebug()<<"余额充足, 自动扣费..";
                    s = QString("update user set balance = %1 where id='%2' ;").arg(hisBalance - totalFee).arg(cusId);
                    qDebug()<<"SQLite query: "<< s;
                    mQuery.exec(s);

                    Userleave(cusId);
                    mPark->setIncome(mPark->getIncome() + totalFee);   // 增加停车场收入额
                    break;
                }

                // 如果余额不够了:
                else{
                    qDebug() << "卡内余额不足, 请缴费..";
                    double payValue = 0.0;

                    do{
                        payValue += payMonitor().toDouble();

                        if(payValue > totalFee){
                            chargeMonitor(cusId, payValue - totalFee);
                            mPark->getNowlist()->removeAt(i);
                            Userleave(cusId);

                            mPark->setIncome(mPark->getIncome() + totalFee);  // 增加停车场收入额
                            break;
                        }
                        else{
                            QSound::play(":/new/prefix1/NoEnoughPay.wav");
                            QMessageBox::critical(this, "缴费中..", QString("您没有缴纳足够的费用哦, 请继续支付。"));
                        }

                      }while(payValue < totalFee);
                        QSound::play(":/new/prefix1/PaySuccess.wav");
                        QMessageBox::about(this, "提示", "您已完成缴费..");
                }
            }
        }

    }

    // 结束完出站的工作, 立即检查当前是否有空位了,
    // 如果盈余了空位, 则顺次更新等待队列..
    if(mPark->getRemain() > 0){
        if(!(mPark->getWq()->isEmpty())){
            // 若等待队列不为空..让等待队列队头进站..
            newUserEntry(mPark->getWq()->head()->getPcarId());
            mPark->getWq()->dequeue();

            // displayWaitqueue();
        }else{
            // 若等待队列为空, 则说明无事需要做.. then pass
        }
    }
}

void MainWindow::on_actionAdmin_clicked()
{

}

void MainWindow::on_actionUser_clicked()
{

}

void MainWindow::on_actionHelp_clicked()
{

}

void MainWindow::on_actionAbout_clicked()
{

}

QRect MainWindow::getmStartCarPos() const
{
    return mStartCarPos;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    if( QMessageBox::question(this,
                                 tr("退出"),
                                 tr("确定要退出停车场管理软件吗?"),
                                  QMessageBox::Yes, QMessageBox::No )
                       == QMessageBox::Yes){
        QString es; // 在关闭窗口时将所有的在站列表提取到数据库保存
        // 仅需保存 cusId 和 entry_Time, 之后再次打开程序时,
        // 就可以根据 entry_Time 来计算停车时间与费用
        // (不考虑车在未开启系统时出站的异常情况)

        for(int i=0; i<mPark->getNowlist()->length(); i++){
            Nowinfo *n = mPark->getNowlist()->at(i);
            es = QString("insert into parkingCache VALUES('%1', '%2'); ").arg(n->getCarId()).arg(n->getEn_time());
            qDebug()<<"Excute SQL: [ " << es <<  " ]";
            mQuery.exec(es);

            e->accept();//不会将事件传递给组件的父组件
            qDebug()<<"System Ended..";
        }
    }
    else
      e->ignore();

}
