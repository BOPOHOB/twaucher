#include <QApplication>
#include "tray.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tray t;
    t.show();
    t.testStatus();

    return a.exec();
}
