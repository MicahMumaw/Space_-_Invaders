#include "Enemy_ufo.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand()
#include <QDebug>
#include "Game.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Enemy_ufo::Enemy_ufo(QGraphicsItem *parent)
{
    QPixmap ufo_pic(":/images/ufo.png");
    ufo_pic = ufo_pic.scaled(QSize(enemy_width * 2, enemy_width));
    setPixmap(ufo_pic);
    setPos(enemy_width * 2, enemy_height * 1.2);
//move timer
    QTimer * shiftTimer = new QTimer();
    connect(shiftTimer, SIGNAL(timeout()), this, SLOT(move()));
    shiftTimer->start(13);
}

void Enemy_ufo::move()
{
    setPos(x() + 10, y());
}


