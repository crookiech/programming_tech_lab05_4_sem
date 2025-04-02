#include "ScreenSaver.h"
#include "ui_ScreenSaver.h"
#include "Menu.h"
#include <QMessageBox>

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

/*
void ScreenSaver::on_pushButton_tagGame_clicked()
{
    hide();
    Menu menu(this);
    menu.setModal(true);
    menu.exec();
    show();
}
*/

void ScreenSaver::on_lineEdit_editingFinished()
{
    QString text = ui->lineEdit->text().trimmed();
    QString gameName = "пятнашки";
    if (text == gameName) {
        hide();
        Menu menu(this);
        menu.setModal(true);
        menu.exec();
        show();
    } else {
        QMessageBox::warning(this, "Ошибка", "Такой игры нет.");
    }
}
