#pragma execution_character_set("utf-8")
#include "userqueryform.h"
#include "ui_userqueryform.h"

UserQueryForm::UserQueryForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserQueryForm)
{
    ui->setupUi(this);
    ui->balanceView->setText("请先输入用户停车卡号");

    bool connect_ok = mDb.open();
      if(connect_ok)  qDebug()<<"Mysql Database connected..";
      else qDebug()<<"Mysql Database connected False..";
    mQuery = QSqlQuery(mDb);

    connect(ui->inputBox, SIGNAL(returnPressed()), this, SLOT(on_pushButton_clicked()));
}

UserQueryForm::~UserQueryForm()
{
    delete ui;
}

void UserQueryForm::initDB()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        qDebug() << "Using Default connection..";
        mDb.database("qt_sql_default_connection");
    }else {

        mDb = QSqlDatabase::addDatabase("QSQLITE");
        mDb.setDatabaseName("parkingUser.db");
    }
}

void UserQueryForm::on_pushButton_clicked()
{
    QString cusId = ui->inputBox->text();
    QString s = QString("select balance from user where id='%1' ;").arg(cusId);
    mQuery.exec(s);

    double hisBalance;
    while (mQuery.next()) {
        qDebug() << "mquery hasNext.. ";
        hisBalance = mQuery.value(0).toDouble();
    }

    ui->balanceView->setText(QString::number(hisBalance, 'f', 2));
}
