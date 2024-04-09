#include "Laser.h"
#include "Barrier.h"
#include "Enemy.h"
#include "Game.h"
#include "qgraphicsscene.h"
#include <QTimer>
#include <QList>

extern Game * game;

Laser::Laser(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Assign pixmap to item
    QPixmap bullet_pixmap(":/images/bullet2.png");
    bullet_pixmap = bullet_pixmap.scaled(10, 50);
    setPixmap(QPixmap(bullet_pixmap));
    setPos(x() + 100, 100);

    qDebug() << game->getGameScreenHeight(); // this is a problem, get function is just causing a crash when called


    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void Laser::move()
{
    //If Laser collides with enemy, destroy both
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase score
            //game->score->increase();
            //removing from scene, but they still exist in memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deleting to remove memory usage
            delete colliding_items[i];
            delete this;
            return; //returns to not create errors with the code below to move the Laser
        }
        if (typeid(*(colliding_items[i])) == typeid(Barrier))
        {
            //removing from scene, but they still exist in memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //deleting to remove memory usage
            delete colliding_items[i];
            delete this;
            return; //returns to not create errors with the code below to move the Laser
        }
    }

    //moving Laser up
    setPos(x(), y() - 5);
    if (pos().y() + 50 < 0)
    {
        scene()->removeItem(this);
        delete this;

    }
}
