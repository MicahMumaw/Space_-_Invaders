#include "menu.h"
#include "Game.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
//    Game w; // FOR USE IN TESTING GAME STUFF
    w.show(); // will show the menu screen on start up

    return a.exec();
}

//LIST OF THINGS TO DO
//Micah TODO
//Multiple alien types, make them move faster as time progresses, multiple levels
//Micah Done
//Aliens shooting randomly, shooting cooldown


