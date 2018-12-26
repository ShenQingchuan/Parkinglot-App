/********************************************************************************
** Form generated from reading UI file 'userqueryform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERQUERYFORM_H
#define UI_USERQUERYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserQueryForm
{
public:
    QPushButton *pushButton;
    QLabel *queryTitle;
    QLabel *inputLabel;
    QLabel *balanceLabel;
    QLabel *balanceView;
    QLineEdit *inputBox;

    void setupUi(QDialog *UserQueryForm)
    {
        if (UserQueryForm->objectName().isEmpty())
            UserQueryForm->setObjectName(QStringLiteral("UserQueryForm"));
        UserQueryForm->resize(400, 300);
        pushButton = new QPushButton(UserQueryForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 210, 151, 51));
        pushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\345\272\267\344\277\252\351\207\221\351\273\221W8(P)\";"));
        queryTitle = new QLabel(UserQueryForm);
        queryTitle->setObjectName(QStringLiteral("queryTitle"));
        queryTitle->setGeometry(QRect(100, 20, 201, 71));
        queryTitle->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\345\272\267\344\277\252\351\207\221\351\273\221W8(P)\";"));
        inputLabel = new QLabel(UserQueryForm);
        inputLabel->setObjectName(QStringLiteral("inputLabel"));
        inputLabel->setGeometry(QRect(40, 80, 91, 41));
        inputLabel->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\255\211\347\272\277\";"));
        balanceLabel = new QLabel(UserQueryForm);
        balanceLabel->setObjectName(QStringLiteral("balanceLabel"));
        balanceLabel->setGeometry(QRect(30, 140, 91, 41));
        balanceLabel->setStyleSheet(QString::fromUtf8("font: 75 16pt \"\347\255\211\347\272\277\";"));
        balanceView = new QLabel(UserQueryForm);
        balanceView->setObjectName(QStringLiteral("balanceView"));
        balanceView->setGeometry(QRect(120, 140, 271, 41));
        balanceView->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\347\255\211\347\272\277\";"));
        inputBox = new QLineEdit(UserQueryForm);
        inputBox->setObjectName(QStringLiteral("inputBox"));
        inputBox->setGeometry(QRect(140, 80, 231, 41));
        inputBox->setStyleSheet(QString::fromUtf8("font: 14pt \"\347\255\211\347\272\277\";"));

        retranslateUi(UserQueryForm);

        QMetaObject::connectSlotsByName(UserQueryForm);
    } // setupUi

    void retranslateUi(QDialog *UserQueryForm)
    {
        UserQueryForm->setWindowTitle(QApplication::translate("UserQueryForm", "\347\224\250\346\210\267\344\275\231\351\242\235\346\237\245\350\257\242", nullptr));
        pushButton->setText(QApplication::translate("UserQueryForm", "\346\237\245\350\257\242\345\215\241\345\206\205\344\275\231\351\242\235", nullptr));
        queryTitle->setText(QApplication::translate("UserQueryForm", "\347\224\250\346\210\267\345\201\234\350\275\246\345\215\241\346\237\245\350\257\242", nullptr));
        inputLabel->setText(QApplication::translate("UserQueryForm", "\350\276\223\345\205\245\350\275\246\347\211\214\345\217\267", nullptr));
        balanceLabel->setText(QApplication::translate("UserQueryForm", "\344\275\231\351\242\235:", nullptr));
        balanceView->setText(QApplication::translate("UserQueryForm", "0.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserQueryForm: public Ui_UserQueryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERQUERYFORM_H
