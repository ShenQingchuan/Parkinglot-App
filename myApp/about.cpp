#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->githubLogo->setPixmap(QPixmap(":/new/prefix1/GitHub.png").scaled(ui->githubLogo->size()));
}

About::~About()
{
    delete ui;
}
