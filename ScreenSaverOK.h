#ifndef SCREENSAVEROK_H
#define SCREENSAVEROK_H

#include <QMainWindow>

namespace Ui {
class ScreenSaverOK;
}

class ScreenSaverOK : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScreenSaverOK(QWidget *parent = nullptr);
    ~ScreenSaverOK();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ScreenSaverOK *ui;
};

#endif // SCREENSAVEROK_H
