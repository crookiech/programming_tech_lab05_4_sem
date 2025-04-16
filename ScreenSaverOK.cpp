#include "ScreenSaverOK.h"
#include "ui_ScreenSaverOK.h"
#include "MenuOK.h"

ScreenSaverOK::ScreenSaverOK(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenSaverOK)
{
    ui->setupUi(this);
}

ScreenSaverOK::~ScreenSaverOK()
{
    delete ui;
}

void ScreenSaverOK::on_pushButton_clicked()
{
    hide();
    MenuOK menu(this);
    menu.setModal(true);
    menu.exec();
    show();
}

