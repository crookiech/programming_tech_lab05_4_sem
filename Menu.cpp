#include "Menu.h"
#include "MenuTests.cpp"
#include "ui_Menu.h"
#include "ClassicTagGameWindow.h"
#include "RateYourMindPalWindow.h"
#include <QMessageBox>
#include <iostream>

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

bool Menu::isValidClassicName(QString gameName) {
    return gameName == "классические пятнашки";
}

bool Menu::isValidRateName(QString gameName) {
    return gameName == "rate your mind pal";
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

