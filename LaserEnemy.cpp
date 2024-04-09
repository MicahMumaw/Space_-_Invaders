#include "LaserEnemy.h"
#include "Barrier.h"
#include "Enemy.h"
#include "Game.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <QList>

extern Game * game;

LaserEnemy::LaserEnemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Assign pixmap to item
    QPixmap bullet_pixmap(":/images/bullet2.png");
    bullet_pixmap = bullet_pixmap.scaled(10, 50);
    setPixmap(QPixmap(bullet_pixmap));
    setPos(x() + 100, 100);

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void LaserEnemy::move()
{
    //moving Laser Down
    setPos(x(), y() + 5);
    if (pos().y() + 50 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

