#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include <QTimer>
#include <QString>

class Customer : public QObject
{
    Q_OBJECT
private:
    double balance;
    QString pcarId;
    QString total;
    int bonus;

    int curStaytime_d;
    QString curStaytime;
    QTimer *wTimer;

public:
    explicit Customer(QObject *parent = nullptr);
    Customer(QObject *parent = nullptr, QString id = "");
    ~Customer();

    void incWaittime();

    double getBalance() const;
    void setBalance(double value);
    QString getPcarId() const;
    void setPcarId(const QString &value);
    QString getTotal() const;
    void setTotal(const QString &value);
    int getBonus() const;
    void setBonus(int value);
    void setCurStaytime(const QString &value);
    QString getCurStaytime();

private slots:
    void singleWaitRefresh();

};

#endif // CUSTOMER_H
