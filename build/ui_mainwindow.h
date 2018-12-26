/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUser;
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralWidget;
    QLabel *status_label;
    QLabel *waitqueue_label;
    QTableWidget *waitqueue_table;
    QLabel *parkinglotGraphics;
    QLabel *pkTwoGraphics;
    QPushButton *refreshBtn;
    QLabel *income;
    QLabel *income_label;
    QPushButton *entryBtn;
    QLabel *logo;
    QLabel *remain_label;
    QPushButton *leaveBtn;
    QLabel *nowlist_label;
    QLabel *remain;
    QTableWidget *nowlist_table;
    QLabel *announce_label;
    QLabel *carGraphics;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuCommand;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1817, 949);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionUser = new QAction(MainWindow);
        actionUser->setObjectName(QStringLiteral("actionUser"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        status_label = new QLabel(centralWidget);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setGeometry(QRect(100, 10, 371, 111));
        status_label->setStyleSheet(QString::fromUtf8("font: 75 25pt \"\347\255\211\347\272\277\";"));
        waitqueue_label = new QLabel(centralWidget);
        waitqueue_label->setObjectName(QStringLiteral("waitqueue_label"));
        waitqueue_label->setGeometry(QRect(370, 610, 271, 31));
        waitqueue_label->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\347\255\211\347\272\277\";"));
        waitqueue_table = new QTableWidget(centralWidget);
        if (waitqueue_table->columnCount() < 2)
            waitqueue_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        waitqueue_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        waitqueue_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        waitqueue_table->setObjectName(QStringLiteral("waitqueue_table"));
        waitqueue_table->setGeometry(QRect(30, 650, 651, 231));
        parkinglotGraphics = new QLabel(centralWidget);
        parkinglotGraphics->setObjectName(QStringLiteral("parkinglotGraphics"));
        parkinglotGraphics->setGeometry(QRect(380, 280, 571, 341));
        pkTwoGraphics = new QLabel(centralWidget);
        pkTwoGraphics->setObjectName(QStringLiteral("pkTwoGraphics"));
        pkTwoGraphics->setGeometry(QRect(470, 60, 361, 261));
        refreshBtn = new QPushButton(centralWidget);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));
        refreshBtn->setGeometry(QRect(880, 120, 101, 61));
        refreshBtn->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\347\255\211\347\272\277\";"));
        income = new QLabel(centralWidget);
        income->setObjectName(QStringLiteral("income"));
        income->setGeometry(QRect(1160, 100, 81, 51));
        income->setStyleSheet(QStringLiteral("font: 75 16pt \"Berlin Sans FB\";"));
        income_label = new QLabel(centralWidget);
        income_label->setObjectName(QStringLiteral("income_label"));
        income_label->setGeometry(QRect(1040, 100, 101, 51));
        income_label->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\347\255\211\347\272\277\";"));
        entryBtn = new QPushButton(centralWidget);
        entryBtn->setObjectName(QStringLiteral("entryBtn"));
        entryBtn->setGeometry(QRect(700, 650, 291, 111));
        entryBtn->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\255\211\347\272\277\";"));
        logo = new QLabel(centralWidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(1300, 40, 421, 181));
        remain_label = new QLabel(centralWidget);
        remain_label->setObjectName(QStringLiteral("remain_label"));
        remain_label->setGeometry(QRect(1030, 170, 121, 41));
        remain_label->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\347\255\211\347\272\277\";"));
        leaveBtn = new QPushButton(centralWidget);
        leaveBtn->setObjectName(QStringLiteral("leaveBtn"));
        leaveBtn->setGeometry(QRect(700, 780, 291, 101));
        leaveBtn->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\255\211\347\272\277\";"));
        nowlist_label = new QLabel(centralWidget);
        nowlist_label->setObjectName(QStringLiteral("nowlist_label"));
        nowlist_label->setGeometry(QRect(1200, 230, 451, 71));
        nowlist_label->setStyleSheet(QString::fromUtf8("font: 25 25pt \"\347\255\211\347\272\277 Light\";"));
        remain = new QLabel(centralWidget);
        remain->setObjectName(QStringLiteral("remain"));
        remain->setGeometry(QRect(1170, 160, 71, 51));
        remain->setStyleSheet(QStringLiteral("font: 24pt \"Berlin Sans FB\";"));
        nowlist_table = new QTableWidget(centralWidget);
        if (nowlist_table->columnCount() < 4)
            nowlist_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        nowlist_table->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        nowlist_table->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        nowlist_table->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        nowlist_table->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        nowlist_table->setObjectName(QStringLiteral("nowlist_table"));
        nowlist_table->setEnabled(true);
        nowlist_table->setGeometry(QRect(1040, 310, 731, 491));
        nowlist_table->setMinimumSize(QSize(651, 0));
        announce_label = new QLabel(centralWidget);
        announce_label->setObjectName(QStringLiteral("announce_label"));
        announce_label->setGeometry(QRect(870, 30, 321, 71));
        announce_label->setStyleSheet(QString::fromUtf8("font: 75 25pt \"\347\255\211\347\272\277\";"));
        carGraphics = new QLabel(centralWidget);
        carGraphics->setObjectName(QStringLiteral("carGraphics"));
        carGraphics->setGeometry(QRect(20, 280, 251, 191));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1817, 26));
        menuCommand = new QMenu(menuBar);
        menuCommand->setObjectName(QStringLiteral("menuCommand"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuCommand->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCommand->addAction(actionUser);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionUser->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\237\245\350\257\242\345\267\245\345\205\267", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\345\270\256\345\212\251", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", nullptr));
        status_label->setText(QApplication::translate("MainWindow", "\342\200\224 \347\253\231\345\206\205\347\233\221\346\216\247\347\224\273\351\235\242 \342\200\224", nullptr));
        waitqueue_label->setText(QApplication::translate("MainWindow", "\342\200\224\342\200\224\342\200\224\342\200\224 \347\253\231\345\206\205\346\216\222\351\230\237\351\230\237\345\210\227 \342\200\224\342\200\224\342\200\224\342\200\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem = waitqueue_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = waitqueue_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\345\267\262\347\255\211\345\276\205\346\227\266\351\225\277(\347\247\222)", nullptr));
        parkinglotGraphics->setText(QString());
        pkTwoGraphics->setText(QString());
        refreshBtn->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        income->setText(QApplication::translate("MainWindow", "0.00", nullptr));
        income_label->setText(QApplication::translate("MainWindow", "\346\224\266\345\205\245\351\242\235", nullptr));
        entryBtn->setText(QApplication::translate("MainWindow", "\345\210\267\345\215\241\350\277\233\347\253\231", nullptr));
        logo->setText(QString());
        remain_label->setText(QApplication::translate("MainWindow", "\344\275\231\350\275\246\344\275\215\346\225\260", nullptr));
        leaveBtn->setText(QApplication::translate("MainWindow", "\347\273\223\347\256\227\345\207\272\347\253\231", nullptr));
        nowlist_label->setText(QApplication::translate("MainWindow", "\342\200\224\342\200\224 \345\234\250\347\253\231\350\275\246\350\276\206\345\210\227\350\241\250 \342\200\224\342\200\224", nullptr));
        remain->setText(QApplication::translate("MainWindow", "50", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = nowlist_table->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = nowlist_table->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\345\205\245\347\253\231\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = nowlist_table->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\345\267\262\345\201\234\346\227\266\351\225\277(\347\247\222)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = nowlist_table->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\350\264\271\347\224\250(\345\205\203)", nullptr));
        announce_label->setText(QApplication::translate("MainWindow", "\342\200\224\342\200\224 \345\205\254\345\221\212\347\211\214 \342\200\224\342\200\224", nullptr));
        carGraphics->setText(QString());
        menuCommand->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\350\217\234\345\215\225", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
