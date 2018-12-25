/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *authorLabel;
    QLabel *githubUrlLabel;
    QLabel *githubLogo;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(400, 225);
        authorLabel = new QLabel(About);
        authorLabel->setObjectName(QStringLiteral("authorLabel"));
        authorLabel->setGeometry(QRect(80, 10, 241, 61));
        authorLabel->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\345\272\267\344\277\252\351\207\221\351\273\221W8\";"));
        githubUrlLabel = new QLabel(About);
        githubUrlLabel->setObjectName(QStringLiteral("githubUrlLabel"));
        githubUrlLabel->setGeometry(QRect(10, 150, 381, 71));
        githubUrlLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\226\260\351\255\217\";"));
        githubLogo = new QLabel(About);
        githubLogo->setObjectName(QStringLiteral("githubLogo"));
        githubLogo->setGeometry(QRect(131, 64, 121, 101));
        githubUrlLabel->raise();
        authorLabel->raise();
        githubLogo->raise();

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "\345\205\263\344\272\216\344\275\234\350\200\205", nullptr));
        authorLabel->setText(QApplication::translate("About", "\345\210\266\344\275\234\350\200\205: \346\262\210\351\235\222\345\267\235", nullptr));
        githubUrlLabel->setText(QApplication::translate("About", "GitHub: https://github.com/ShenQingchuan", nullptr));
        githubLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
