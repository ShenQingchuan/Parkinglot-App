#ifndef NOWINFO_H
#define NOWINFO_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QDebug>

class Nowinfo : public QObject
{
    Q_OBJECT
private:
    QString carId;
    qint64 en_time_d;
    QString en_time;    // 通过QDateTime类的对象.tostring()生成
    QString stay_time;  // 同上
    double fee;
    QTimer *eTimer;

public:
    explicit Nowinfo(QObject *parent = nullptr);
    Nowinfo(QObject *parent = nullptr, QString cId = "");
    ~Nowinfo();

    void incStaytime();
    QString getCarId() const;
    QString getEn_time() const;
    QString getStay_time() const;
    double getFee() const;

    void setStay_time(const QString &value);

    qint64 getEn_time_d() const;
    void setEn_time_d(const qint64 &value);

private slots:
    void singleRefresh();

};

/* Qt随学笔记:
    QDateTime类，头文件 include <QDateTime>
    可以使用QDateTime类来获得系统时间。
    通过QDateTime::currentDateTime()来获取本地系统的时间和日期信号。
    可以通过date()和time()来返回
    datetime中的日期和时间部分，代码如下：
    QDateTime *datetime=new QDateTime(QDateTime::currentDateTime());
    QString s=datetime->date().tostring();
*/


#endif // NOWINFO_H
