#ifndef MENUOK_H
#define MENUOK_H

#include <QDialog>

namespace Ui {
class MenuOK;
}

class MenuOK : public QDialog
{
    Q_OBJECT

public:
    explicit MenuOK(QWidget *parent = nullptr);
    ~MenuOK();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MenuOK *ui;
};

#endif // MENUOK_H
