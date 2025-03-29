#ifndef CLASSICTAGGAMEWINDOW_H
#define CLASSICTAGGAMEWINDOW_H

#include <QDialog>
#include "CreateTagGame.h"
#include "TagGame.h"

namespace Ui {
class ClassicTagGameWindow;
}

class ClassicTagGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClassicTagGameWindow(QWidget *parent = nullptr);
    ~ClassicTagGameWindow();

private slots:
    void on_pushButton_trick_clicked();
    void on_pushButton_shuffle_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::ClassicTagGameWindow *ui;
    CreateTagGame* classicFactory;
    TagGame* classicGame;
    QVector<QPushButton*> buttons;
};

#endif
