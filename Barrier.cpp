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
    setBrush( QColorConstants::Svg::violet );
    setRect(0, 0, barrier_width, barrier_height);
    barrierhealth = 0;
}

int Barrier::getBarrierhealth() const
{
    return barrierhealth;
}

