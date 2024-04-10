#include "menu.h"
#include "Game.h"
#include <QApplication>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Menu w;
    Game w; // FOR USE IN TESTING GAME STUFF
    w.show();

    return a.exec();
}

//LIST OF THINGS TO DO
//Make everything work on Cheka's screen size - 1366, 768
// - barriers - good
// - enemies - good
// - player -


//add pixmaps
//barrier health
//get enemies to shoot
//Reload timer
//clean up code

//problems
// - still can't do function calls to game
// - connecting a timer to spawn enemy laser in game.cpp
