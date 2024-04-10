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
    setRect(0, 0, 100, 50);
}

