#include "ClassicMoveWindow.h"
#include "ui_ClassicMoveWindow.h"
#include "TagGame.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

ClassicMoveWindow::ClassicMoveWindow(int buttonIndex, TagGame* classicGame, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassicMoveWindow),
    buttonIndex(buttonIndex),
    classicGame(classicGame)
{
    ui->setupUi(this);
    ui->label->setText(QString("Выберите, куда будете ходить фишкой ") + QString::number(buttonIndex));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_step_clicked()));
}

ClassicMoveWindow::~ClassicMoveWindow()
{
    delete ui;
}

void ClassicMoveWindow::on_pushButton_step_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString objectName = button->objectName();
    int index = objectName.remove("pushButton_").toInt();
    classicGame->Move(buttonIndex, index);
    if (index == 1) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::number(buttonIndex) + " перемещена вверх", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else if (index == 2) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::number(buttonIndex) + " перемещена вниз", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else if (index == 3) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::number(buttonIndex) + " перемещена влево", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    } else if (index == 4) {
        QDialog information(this);
        information.setWindowTitle("Информация");
        QVBoxLayout* layout = new QVBoxLayout(&information);
        QLabel* label = new QLabel("Фишка " + QString::number(buttonIndex) + " перемещена вправо", &information);
        QPushButton* okButton = new QPushButton("OK", &information);
        layout->addWidget(label);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
        information.exec();
    }
    accept();
}
