#include "LaserEnemy.h"
#include "Barrier.h"
#include "Game.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <QList>

extern Game * game;
int barrierhealth = 0;
int shiphealth=0;

LaserEnemy::LaserEnemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Assign pixmap to item
    QPixmap bullet_pixmap(":/images/bullet2.png");
    bullet_pixmap = bullet_pixmap.scaled(laser_width, laser_height);
    setPixmap(QPixmap(bullet_pixmap));
    setPos(x() + 100, 100);

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(5);
}

void LaserEnemy::move()
{
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            switch(game->health->getHealth()){
                case 3:
                    //decrease health
                    game->health->decrease();
                    scene()->removeItem(this);
                    delete this;
                    // put new picture
                    return;
                case 2:
                    //decrease health
                    game->health->decrease();
                    scene()->removeItem(this);
                    delete this;
                    //put new picture
                    return;
                case 1:
                    //decrease health
                    game->health->decrease();
                    //removing from scene, but they still exist in memory
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    //deleting to remove memory usage
                    delete colliding_items[i];
                    delete this;
                    return;
                default:
                    return;
            }

        }
        if (typeid(*(colliding_items[i])) == typeid(Barrier))
        {
            //removing from scene, but they still exist in memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //deleting to remove memory usage
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //moving Laser Down
    setPos(x(), y() + 1);
    if (pos().y() > gameScreenHeight)
    {
        scene()->removeItem(this);
        delete this;
    }
}

