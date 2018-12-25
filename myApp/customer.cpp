#include "customer.h"
#include <QDebug>

Customer::Customer(QObject *parent) : QObject(parent)
{
    balance = 0;
    total = "";
    bonus = 0;
    curStaytime_d = 0;
}

Customer::Customer(QObject *parent, QString id): QObject(parent), pcarId(id){
    // with Params Constructor
    balance = 0;
    total = "";
    bonus = 0;
    curStaytime_d = 0;

    wTimer = new QTimer(this);
    connect(wTimer, SIGNAL(timeout()), this, SLOT(singleWaitRefresh()));
    wTimer->start(1000);
}

Customer::~Customer(){ /* destroyed.. */ }


double Customer::getBalance() const
{
    return balance;
}

void Customer::setBalance(double value)
{
    balance = value;
}

QString Customer::getPcarId() const
{
    return pcarId;
}

void Customer::setPcarId(const QString &value)
{
    pcarId = value;
}

QString Customer::getTotal() const
{
    return total;
}

void Customer::setTotal(const QString &value)
{
    total = value;
}

int Customer::getBonus() const
{
    return bonus;
}

void Customer::setBonus(int value)
{
    bonus = value;
}

void Customer::singleWaitRefresh()
{
    incWaittime();

}

void Customer::setCurStaytime(const QString &value)
{
    curStaytime = value;
}

QString Customer::getCurStaytime()
{
    return curStaytime;
}

void Customer::incWaittime()
{
    // 增长排队时间
    curStaytime_d ++;
    QString s = QString::number(curStaytime_d);
    this->setCurStaytime(s);
}
