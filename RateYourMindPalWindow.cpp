#include "RateYourMindPalWindow.h"
#include "ui_RateYourMindPalWindow.h"
#include "Menu.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QRandomGenerator>
#include <algorithm>

RateYourMindPalWindow::RateYourMindPalWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RateYourMindPalWindow),
    rateFactory(nullptr),
    rateGame(nullptr)
{
    rateFactory = new CreateRateYourMindPal();
    rateGame = rateFactory->FactoryMethod();
    ui->setupUi(this);
    buttons = {
        ui->pushButton_1, ui->pushButton_2, ui->pushButton_3,
        ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
        ui->pushButton_7, ui->pushButton_8, ui->pushButton_9,
        ui->pushButton_10, ui->pushButton_11, ui->pushButton_12,
        ui->pushButton_13, ui->pushButton_14, ui->pushButton_15
    };
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
    for (int i = 0; i < buttons.size(); ++i) {
        buttons[i]->setProperty("buttonIndex", i + 1);
    }
}

RateYourMindPalWindow::~RateYourMindPalWindow()
{
    delete rateGame;
    delete rateFactory;
    delete ui;
}

void RateYourMindPalWindow::on_pushButton_shuffle_clicked()
{
    rateGame->Shuffle();
    QVector<QRect> geometries;
    for (QPushButton* button : buttons) {
        geometries.append(button->geometry());
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(geometries.begin(), geometries.end(), g);
    for (int i = 0; i < buttons.size(); ++i) {
        buttons[i]->setGeometry(geometries[i]);
    }
    QDialog information(this);
    information.setWindowTitle("Информация");
    QVBoxLayout* layout = new QVBoxLayout(&information);
    QLabel* label = new QLabel("Поле перемешано", &information);
    QPushButton* okButton = new QPushButton("OK", &information);
    layout->addWidget(label);
    layout->addWidget(okButton);
    QObject::connect(okButton, &QPushButton::clicked, &information, &QDialog::accept);
    information.exec();
}

void RateYourMindPalWindow::on_pushButton_trick_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString objectName = button->objectName();
    int index = objectName.remove("pushButton_").toInt();
    int buttonIndex = button->property("buttonIndex").toInt();
    QPushButton* movingButton = nullptr;
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->property("buttonIndex").toInt() == buttonIndex) {
            movingButton = buttons[i];
            break;
        }
    }
    if (!movingButton) {
        QMessageBox::critical(this, "Ошибка", "Не удалось найти кнопку для перемещения.");
        return;
    }
    QRect movingButtonRect = movingButton->geometry();
    int buttonWidth = movingButtonRect.width();
    int buttonHeight = movingButtonRect.height();
    int spacing = 7;
    enum Direction { UP, DOWN, LEFT, RIGHT, NONE };
    Direction possibleDirections[4] = {UP, DOWN, LEFT, RIGHT};
    bool directionAvailable[4] = {true, true, true, true};
    auto isButtonAt = [&](int x, int y) {
        for (QPushButton* otherButton : buttons) {
            if (otherButton == movingButton) continue;
            QRect otherButtonRect = otherButton->geometry();
            if (otherButtonRect.x() == x && otherButtonRect.y() == y) {
                return true;
            }
        }
        return false;
    };
    int targetX_UP = movingButtonRect.x();
    int targetY_UP = movingButtonRect.y() - (buttonHeight + spacing);

    if (targetY_UP < 46 || isButtonAt(targetX_UP, targetY_UP)) {
        directionAvailable[0] = false;
    }
    int targetX_DOWN = movingButtonRect.x();
    int targetY_DOWN = movingButtonRect.y() + (buttonHeight + spacing);

    if (targetY_DOWN > 250 || isButtonAt(targetX_DOWN, targetY_DOWN)) {
        directionAvailable[1] = false;
    }
    int targetX_LEFT = movingButtonRect.x() - (buttonWidth + spacing);
    int targetY_LEFT = movingButtonRect.y();

    if (targetX_LEFT < 74 || isButtonAt(targetX_LEFT, targetY_LEFT)) {
        directionAvailable[2] = false;
    }
    int targetX_RIGHT = movingButtonRect.x() + (buttonWidth + spacing);
    int targetY_RIGHT = movingButtonRect.y();
    if (targetX_RIGHT > 278 || isButtonAt(targetX_RIGHT, targetY_RIGHT)) {
        directionAvailable[3] = false;
    }
    Direction selectedDirection = NONE;
    for (int i = 0; i < 4; ++i) {
        if (directionAvailable[i]) {
            selectedDirection = possibleDirections[i];
            break;
        }
    }
    if (selectedDirection == NONE) {
        QMessageBox::warning(this, "Ошибка", "Нет доступных мест для перемещения фишки.");
        return;
    }
    int targetX = 0;
    int targetY = 0;
    switch (selectedDirection) {
        case UP:
            targetX = targetX_UP;
            targetY = targetY_UP;
            break;
        case DOWN:
            targetX = targetX_DOWN;
            targetY = targetY_DOWN;
            break;
        case LEFT:
            targetX = targetX_LEFT;
            targetY = targetY_LEFT;
            break;
        case RIGHT:
            targetX = targetX_RIGHT;
            targetY = targetY_RIGHT;
            break;
        default:
            QMessageBox::critical(this, "Ошибка", "Неожиданная ошибка при определении направления перемещения.");
        return;
    }
    QRect targetRect = movingButtonRect;
    targetRect.moveTopLeft(QPoint(targetX, targetY));
    movingButton->setGeometry(targetRect);
    rateGame->Move(buttonIndex, index);
    for (int i = 0; i < buttons.size(); ++i) {
        buttons[i]->setProperty("buttonIndex", i + 1);
    }
}

void RateYourMindPalWindow::on_pushButton_exit_clicked()
{
    hide();
    Menu menu;
    menu.setModal(true);
    menu.exec();
}
