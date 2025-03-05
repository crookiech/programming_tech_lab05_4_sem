#ifndef CLASSICMOVEWINDOW_H
#define CLASSICMOVEWINDOW_H

#include <QDialog>
#include "TagGame.h"

namespace Ui {
class ClassicMoveWindow;
}

class ClassicMoveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClassicMoveWindow(int buttonIndex, TagGame* classicGame, QWidget *parent = nullptr);
    ~ClassicMoveWindow();

private:
    Ui::ClassicMoveWindow *ui;
    int buttonIndex;
    TagGame* classicGame;

private slots:
    void on_pushButton_step_clicked();
};

#endif
