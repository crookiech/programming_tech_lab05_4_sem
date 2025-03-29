#ifndef RATEYOURMINDPALWINDOW_H
#define RATEYOURMINDPALWINDOW_H
#include <QDialog>
#include "CreateTagGame.h"
#include "TagGame.h"

namespace Ui {
class RateYourMindPalWindow;
}

class RateYourMindPalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RateYourMindPalWindow(QWidget *parent = nullptr);
    ~RateYourMindPalWindow();

private slots:
    void on_pushButton_shuffle_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_trick_clicked();

private:
    Ui::RateYourMindPalWindow *ui;
    CreateTagGame* rateFactory;
    TagGame* rateGame;
    QVector<QPushButton*> buttons;
};

#endif
