#include "RateMoveWindow.h"
#include "ui_RateMoveWindow.h"
#include "TagGame.h"
#include <QMessageBox.h>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

RateMoveWindow::RateMoveWindow(int buttonIndex, TagGame* rateGame, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RateMoveWindow),
    buttonIndex(buttonIndex),
    rateGame(rateGame),
    trickNumber("")
{
    ui->setupUi(this);
    std::map<int, std::string> trickMap = {
       {1, "R"}, {8, "R"},
       {2, "A"}, {14, "A"},
       {3, "T"},
       {4, "E"},
       {5, "Y"},
       {6, "O"},
       {7, "U"},
       {9, "M"},
       {10, "I"},
       {11, "N"},
       {12, "D"},
       {13, "P"},
       {15, "L"}
   };
    auto it = trickMap.find(buttonIndex);
    if (it != trickMap.end()) {
       trickNumber = it->second;
    } else {
       trickNumber = "Unknown";
    }
    ui->label->setText(QString("Выберите, куда будете ходить фишкой ") + QString::fromStdString(trickNumber));
    // ui->label->setText(QString("Выберите, куда будете ходить фишкой ") + trickNumber);
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
}

RateMoveWindow::~RateMoveWindow()
{
    delete ui;
}

void RateMoveWindow::on_pushButton_step_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString objectName = button->objectName();
    int index = objectName.remove("pushButton_").toInt();
    rateGame->Move(buttonIndex, index);
    if (index == 1) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::fromStdString(trickNumber) + " перемещена вверх", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else if (index == 2) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::fromStdString(trickNumber) + " перемещена вниз", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else if (index == 3) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::fromStdString(trickNumber) + " перемещена влево", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else if (index == 4) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::fromStdString(trickNumber) + " перемещена вправо", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    }
    accept();
}
