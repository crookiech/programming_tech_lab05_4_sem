#include "ScreenSaver.h"
#include "ScreenSaverTests.cpp"
#include "ui_ScreenSaver.h"
#include "Menu.h"
#include <QMessageBox>
#include <iostream>
#include <QStatusBar>
#include <QLabel>

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

bool ScreenSaver::isValidGameName(QString gameName) {
    gameName = gameName.toLower();
    gameName = gameName.replace(" ", "");
    return gameName == "пятнашки";
}

void ScreenSaver::on_lineEdit_editingFinished()
{
    std::cout << "test_correct_text..." << std::flush;
    test_correct_text();
    std::cout << "OK" << std::endl;

    std::cout << "test_upper_text..." << std::flush;
    test_upper_text();
    std::cout << "OK" << std::endl;

    std::cout << "test_spaces_text..." << std::flush;
    test_spaces_text();
    std::cout << "OK" << std::endl;

    std::cout << "test_hell_text..." << std::flush;
    test_hell_text();
    std::cout << "OK" << std::endl;

    QString text = ui->lineEdit->text();
    if (isValidGameName(text)) {
        hide();
        Menu menu(this);
        menu.setModal(true);
        menu.exec();
        show();
    } else {
        QMessageBox::warning(this, "Ошибка", "Такой игры нет");
    }
}
