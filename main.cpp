#include "menu.h"
#include "Game.h"
#include <QApplication>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
    w.show();

    return a.exec();
}
