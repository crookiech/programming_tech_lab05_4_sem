#include "MenuOK.h"
#include "ui_MenuOK.h"
#include "ClassicTagGameWindow.h"
#include "RateYourMindPalWindow.h"
#include <QMessageBox>
#include <iostream>

MenuOK::MenuOK(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuOK)
{
    ui->setupUi(this);
    ui->classes->addItem("Classic Tag Game");
    ui->classes->addItem("Rate Your Mind Pal");
}

MenuOK::~MenuOK()
{
    delete ui;
}

void MenuOK::on_pushButton_clicked()
{
    QString className = ui->classes->currentText();
    if (className == "Classic Tag Game") {
        hide();
        ClassicTagGameWindow window;
        window.setModal(true);
        window.exec();
    } else if (className == "Rate Your Mind Pal") {
        hide();
        RateYourMindPalWindow window;
        window.setModal(true);
        window.exec();
    }
}


void MenuOK::on_pushButton_2_clicked()
{
    close();
}

