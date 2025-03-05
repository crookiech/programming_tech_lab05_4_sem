#include "ClassicTagGameWindow.h"
#include "ui_ClassicTagGameWindow.h"
#include "Menu.h"
#include "ClassicMoveWindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

ClassicTagGameWindow::ClassicTagGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassicTagGameWindow),
    classicFactory(nullptr),
    classicGame(nullptr)
{
    classicFactory = new CreateClassicTagGame();
    classicGame = classicFactory->FactoryMethod();
    ui->setupUi(this);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(on_pushButton_trick_clicked()));
}

ClassicTagGameWindow::~ClassicTagGameWindow()
{
    delete classicGame;
    delete classicFactory;
    delete ui;
}

void ClassicTagGameWindow::on_pushButton_shuffle_clicked()
{
    if (classicGame) {
        classicGame->Shuffle();
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Поле перемешано", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else {
        QMessageBox::critical(this,"Ошибка","Игра не создана");
    }
}

void ClassicTagGameWindow::on_pushButton_exit_clicked()
{
    hide();
    Menu menu;
    menu.setModal(true);
    menu.exec();
}

void ClassicTagGameWindow::on_pushButton_trick_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString objectName = button->objectName();
    int index = objectName.remove("pushButton_").toInt();
    ClassicMoveWindow classicMoveWindow(index, classicGame);
    classicMoveWindow.setModal(true);
    classicMoveWindow.exec();
}
