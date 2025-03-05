#ifndef RATEMOVEWINDOW_H
#define RATEMOVEWINDOW_H

#include <QDialog>
#include "TagGame.h"

namespace Ui {
class RateMoveWindow;
}

class RateMoveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RateMoveWindow(int buttonIndex, TagGame* rateGame, QWidget *parent = nullptr);
    ~RateMoveWindow();

private:
    Ui::RateMoveWindow *ui;
    int buttonIndex;
    TagGame* rateGame;
    std::string trickNumber;

private slots:
    void on_pushButton_step_clicked();
};

#endif // RATEMOVEWINDOW_H
