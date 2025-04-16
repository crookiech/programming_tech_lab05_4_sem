#include "ScreenSaver.h"
#include "ScreenSaverOK.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    ScreenSaverOK w;
    w.show();
    return a.exec();
    */
    QApplication a(argc, argv);
    ScreenSaver w;
    w.show();
    return a.exec();

}
