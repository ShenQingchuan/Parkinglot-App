#ifndef PSLOT_H
#define PSLOT_H

#include <QString>

/* Pslot类:
 * 车位类 包含每个车位自己独立的信息与状态。
 * Uifor: 为 status_table 提供数据显示基础
*/

class Pslot
{
private:
    QString pid;
    bool st;
public:
    Pslot() {}// Warninfo: 考虑健壮性提供无参构造函数
    Pslot(QString pid, bool st);

    void stChange();
};

#endif // PSLOT_H
