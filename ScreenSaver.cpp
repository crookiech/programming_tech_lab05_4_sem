#include "ScreenSaver.h"
#include "ui_ScreenSaver.h"
#include "Menu.h"

ScreenSaver::ScreenSaver(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::ScreenSaver)
{
    ui->setupUi(this);
}

ScreenSaver::~ScreenSaver()
{
    delete ui;
}

void ScreenSaver::on_pushButton_tagGame_clicked()
{
    hide();
    Menu menu(this);
    menu.setModal(true);
    menu.exec();
    show();
}
