#include "menu.h"
#include "Game.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
    w.show(); // will show the menu screen on start up

    return a.exec();
}



