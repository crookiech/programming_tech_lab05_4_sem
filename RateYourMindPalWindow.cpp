#include "RateYourMindPalWindow.h"
#include "ui_RateYourMindPalWindow.h"
#include "Menu.h"
#include "RateMoveWindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

RateYourMindPalWindow::RateYourMindPalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RateYourMindPalWindow),
    rateFactory(nullptr),
    rateGame(nullptr)
{
    rateFactory = new CreateRateYourMindPal();
    rateGame = rateFactory->FactoryMethod();
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

RateYourMindPalWindow::~RateYourMindPalWindow()
{
    delete rateGame;
    delete rateFactory;
    delete ui;
}

void RateYourMindPalWindow::on_pushButton_shuffle_clicked()
{
    if (rateGame) {
        rateGame->Shuffle();
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

void RateYourMindPalWindow::on_pushButton_trick_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString objectName = button->objectName();
    int index = objectName.remove("pushButton_").toInt();
    RateMoveWindow rateMoveWindow(index, rateGame);
    rateMoveWindow.setModal(true);
    rateMoveWindow.exec();
}


void RateYourMindPalWindow::on_pushButton_exit_clicked()
{
    hide();
    Menu menu;
    menu.setModal(true);
    menu.exec();
}

