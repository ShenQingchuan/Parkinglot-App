#ifndef USERQUERYFORM_H
#define USERQUERYFORM_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
class UserQueryForm;
}

class UserQueryForm : public QDialog
{
    Q_OBJECT

public:
    explicit UserQueryForm(QWidget *parent = 0);
    ~UserQueryForm();

    void initDB();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserQueryForm *ui;
    QString qbalance;
    double qbalance_d;
    QSqlQuery mQuery;
    QSqlDatabase mDb;
};

#endif // USERQUERYFORM_H
