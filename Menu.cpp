#include "Menu.h"
#include "MenuTests.cpp"
#include "ui_Menu.h"
#include "ClassicTagGameWindow.h"
#include "RateYourMindPalWindow.h"
#include <QMessageBox>
#include <iostream>
#include <QStatusBar>
#include <QLabel>

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_2_clicked()
{
    close();
}

bool Menu::isValidClassicName(QString gameName) {
    gameName = gameName.toLower();
    gameName = gameName.replace(" ", "");
    return gameName == "классическиепятнашки";
}

bool Menu::isValidRateName(QString gameName) {
    gameName = gameName.toLower();
    gameName = gameName.replace(" ", "");
    return gameName == "rateyourmindpal";
}

void Menu::on_lineEdit_editingFinished()
{
    std::cout << "menu_test_correct_text..." << std::flush;
    menu_test_correct_text();
    std::cout << "OK" << std::endl;

    std::cout << "menu_test_upper_text..." << std::flush;
    menu_test_upper_text();
    std::cout << "OK" << std::endl;

    std::cout << "menu_test_spaces_text..." << std::flush;
    menu_test_spaces_text();
    std::cout << "OK" << std::endl;

    std::cout << "menu_test_hell_text..." << std::flush;
    menu_test_hell_text();
    std::cout << "OK" << std::endl;

    QString text = ui->lineEdit->text().trimmed();
    if (isValidClassicName(text)) {
        hide();
        ClassicTagGameWindow window;
        window.setModal(true);
        window.exec();
    } else if (isValidRateName(text)) {
        hide();
        RateYourMindPalWindow window;
        window.setModal(true);
        window.exec();
    } else {
        QMessageBox::warning(this, "Ошибка", "Такого вида игры нет.");
    }
}

