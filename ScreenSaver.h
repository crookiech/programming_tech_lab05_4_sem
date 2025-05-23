#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ScreenSaver; }
QT_END_NAMESPACE

class ScreenSaver : public QMainWindow
{
    Q_OBJECT

public:
    ScreenSaver(QWidget *parent = nullptr);
    ~ScreenSaver();

private slots:
    void on_lineEdit_editingFinished();

public slots:
    bool isValidGameName(QString gameName);

private:
    Ui::ScreenSaver *ui;
};

#endif
