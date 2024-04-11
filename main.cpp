#include "menu.h"
#include "Game.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
//    Game w; // FOR USE IN TESTING GAME STUFF
    w.show();

    return a.exec();
}

//LIST OF THINGS TO DO
//Make everything work on Cheka's screen size - 1366, 768
// - barriers - good
// - enemies - good
// - player - good


//add pixmaps
//barrier health
//get enemies to shoot - they can shoot, just need to randomize better and get function to call on timer
//Reload timer
//clean up code - my files are clean

//problems
// - still can't do function calls to game
// - connecting a timer to spawn enemy laser in game.cpp
