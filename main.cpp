#include "Game.h"
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

//LIST OF THINGS TO DO
//Make everything work on Cheka's screen size
//add pixmaps
//barrier health
//get enemies to shoot
//Reload timer
