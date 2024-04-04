#include "setup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Setup w;
    w.show();

    return a.exec();
}
