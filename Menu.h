#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_2_clicked();
    // void on_pushButton_clicked();
    void on_lineEdit_editingFinished();

public slots:
    bool isValidClassicName(QString gameName);
    bool isValidRateName(QString gameName);

private:
    Ui::Menu *ui;
};

#endif
