#ifndef ANNOUNCE_H
#define ANNOUNCE_H

#include <QString>

/* Announce类:
 * 停车场公告类，含有常规公告和警告信息。
 * Uifor: 为 滚动通知条 提供数据显示基础
*/

class Announce
{
private:
    QString normal;
    QString warning;
public:
    Announce() {} // Warninfo: 考虑健壮性提供无参构造函数
    Announce(QString n, QString w);
};

#endif // ANNOUNCE_H
