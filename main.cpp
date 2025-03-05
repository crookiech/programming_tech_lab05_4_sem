#include "ScreenSaver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScreenSaver w;
    w.show();
    return a.exec();
}
