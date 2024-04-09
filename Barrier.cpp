#include <Barrier.h>
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand() -> really large int
#include <QDebug>
#include "Game.h"
#include "Player.h"

extern Game * game;

Barrier::Barrier()
{
    barrierSpacing = 240;
    barrierWidth = 100;
    setRect(0, 0, 100, 50);

    //qDebug() << game->getGameScreenHeight(); // this is a problem, get function is just causing a crash when called
}

int Barrier::getBarrierSpacing()
{
    return barrierSpacing;
}

int Barrier::getBarrierWidth()
{
    return barrierWidth;
}
