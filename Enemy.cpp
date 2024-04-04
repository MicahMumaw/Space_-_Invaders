#include "Enemy.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand() -> really large int

Enemy::Enemy()
{

    //draw the rectangle
    setRect(0, 0, 50, 50);

    //connect stuff
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(500);
}

void Enemy::move()
{
    //move Enemy down
    setPos(x(), y() + 5);
    if (pos().y() > scene()->height())
    {
        scene()->removeItem(this);
        delete this;
    }
}
