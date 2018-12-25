#pragma execution_character_set("utf-8")
#include "parkinglot.h"

QList<Nowinfo *>* Parkinglot::getNowlist()
{
    return &nowlist;
}


Announce *Parkinglot::getAnnc() const
{
    return annc;
}

QQueue<Customer *> *Parkinglot::getWq()
{
   return &wq;
}



Parkinglot::Parkinglot()
{
    /* 初始化 收入额为0 余车位为50 */
    annc = new Announce();
    mIncome = 0;
    mRemain = 12;
}

double Parkinglot::getIncome(){
    return this->mIncome;
}

void Parkinglot::setIncome(double income){
    this->mIncome = income;
}

int Parkinglot::getRemain(){
    return this->mRemain;
}

void Parkinglot::setRemain(int remain){
    this->mRemain = remain;
}

void Parkinglot::decRemain(){
    this->mRemain --;
}

void Parkinglot::incRemain()
{
    this->mRemain ++;
}
