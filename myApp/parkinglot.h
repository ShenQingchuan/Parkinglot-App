#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "pslot.h"
#include "nowinfo.h"
#include "announce.h"
#include "customer.h"
#include <QQueue>

/* Parkinglot类:
 * 停车场主类 包含停车场的收入、余车位等信息。
 * Uifor: 为 QtMainWindow 整体提供数据显示基础
*/

class Parkinglot
{
private:
    double mIncome; // Parking成员 收入额变量
    int mRemain;    // Parking成员 余车位变量

    // 排队等待的链队列, 需要从wq.head开始访问
    QQueue< Customer* > wq;

    // 所有入站的车辆信息列表:
    QList<Nowinfo *> nowlist;  // 最多能入站7个，多的就空着。
    Announce *annc;   // 停车场公告

public:
    Parkinglot();

    double getIncome();
    void setIncome( double income );
    int getRemain();
    void setRemain( int remain );
    void decRemain();
    void incRemain();
    QList<Nowinfo *>* getNowlist();
    QList<Pslot>* getPs_list();
    Announce *getAnnc() const;
    void setNowlist(const QList<Nowinfo *> &value);
    QQueue<Customer*>* getWq();
};

#endif // PARKINGLOT_H
