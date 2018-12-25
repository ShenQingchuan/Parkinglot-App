#pragma execution_character_set("utf-8")
#include "nowinfo.h"

void Nowinfo::setStay_time(const QString &value)
{
    stay_time = value;
}

qint64 Nowinfo::getEn_time_d() const
{
    return en_time_d;
}

void Nowinfo::setEn_time_d(const qint64 &value)
{
    en_time_d = value;
}

Nowinfo::Nowinfo(QObject *parent) : QObject(parent)
{
    // no Params Costructor.
}

Nowinfo::Nowinfo(QObject *parent, QString cId) : QObject(parent), carId(cId)
{
    en_time_d = 0;
    QDateTime *datetime = new QDateTime(QDateTime::currentDateTime());
    en_time = datetime->currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 费用初始化为 0.00 元
    fee = 0.00;

    eTimer = new QTimer(this);
    connect(eTimer, SIGNAL(timeout()), this, SLOT(singleRefresh()));
    eTimer->start(1000);
}

Nowinfo::~Nowinfo(){ /* destroyed.. */ }

QString Nowinfo::getCarId() const
{
    return carId;
}

QString Nowinfo::getEn_time() const
{
    return en_time;
}

QString Nowinfo::getStay_time() const
{
    return stay_time;
}

double Nowinfo::getFee() const
{
    return fee;
}

void Nowinfo::singleRefresh()
{
    // 每个在站对象的计时器的每一次刷新对应的 操作
    // qDebug() << this->getCarId() <<": refreshing..";
    incStaytime();
    // 设定价格 5元/小时 所以每秒增长 0.00138 元
    this->fee = en_time_d * 0.00138;
}

void Nowinfo::incStaytime()
{
    // 增长入站时间
    en_time_d ++;
    this->setStay_time(QString::number(en_time_d));
}
