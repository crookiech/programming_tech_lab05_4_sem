#include "Menu.h"
#include "ScreenSaver.h"
#include "ui_Menu.h"
#include "ClassicTagGameWindow.h"
#include "RateYourMindPalWindow.h"
#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    /*
    ui->classes->addItem("Classic Tag Game");
    ui->classes->addItem("Rate Your Mind Pal");
    */
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_2_clicked()
{
    close();
}

/*
void Menu::on_pushButton_clicked()
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
*/


void Menu::on_lineEdit_editingFinished()
{
    QString text = ui->lineEdit->text().trimmed();
    QString classic = "классические пятнашки";
    QString rate = "rate your mind pal";
    if (text == classic) {
        hide();
        ClassicTagGameWindow window;
        window.setModal(true);
        window.exec();
    } else if (text == rate) {
        hide();
        RateYourMindPalWindow window;
        window.setModal(true);
        window.exec();
    } else {
        QMessageBox::warning(this, "Ошибка", "Такого вида игры нет.");
    }
}

