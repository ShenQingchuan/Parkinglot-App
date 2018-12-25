#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "parkinglot.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QPropertyAnimation>
#include <QStandardItemModel>
#include <QMovie>
#include <QCloseEvent>
#include <QSound>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initDB();
    bool waitQuestion();
    QString swipeMonitor();
    QString payMonitor();
    void chargeMonitor(QString cusId, double charge);

    // View Controller..
    void refreshRemainView();
    void refreshIncomeView();
    void displayNowlist();
    void displayWaitqueue();
    void newUserEntry(QString cusId);
    void Userleave(QString cusId);
    void updateView();
    void displayRemain();

    // View's..
    QRect getmStartCarPos() const;

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_refreshBtn_clicked();

    void on_entryBtn_clicked();

    void timerRefresh();

    void on_leaveBtn_clicked();

    // 菜单栏槽函数:
    void on_actionAdmin_clicked();
    void on_actionUser_clicked();
    void on_actionHelp_clicked();
    void on_actionAbout_clicked();

private:
    Ui::MainWindow *ui;
    QRect mStartCarPos;
    QRect mEndCarPos;

    Parkinglot *mPark;
    QSqlDatabase mDb;
    QSqlQuery mQuery;
    QTimer *mTimer;
    int mTimeCount;
};

#endif // MAINWINDOW_H
