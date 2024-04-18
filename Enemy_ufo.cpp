#include "Enemy_ufo.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand()
#include <QDebug>
#include "Game.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

void Enemy_ufo::spawn_ufo_laser()
{
    //move timer
    QTimer * shiftTimer = new QTimer();
    connect(shiftTimer, SIGNAL(timeout()), this, SLOT(move()));
    shiftTimer->start(250);
}

void Enemy_ufo::move()
{
    setPos(x(), y() + 15);
}
