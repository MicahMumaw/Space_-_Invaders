#include "Laser.h"
#include "Game.h"

extern Game * game;
int barrierhealth=0;

Laser::Laser(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Assign pixmap to item
    QPixmap bullet_pixmap(":/images/bullet2.png");
    bullet_pixmap = bullet_pixmap.scaled(6, 40);
    setPixmap(QPixmap(bullet_pixmap));
    setPos(x() + 100, 100);

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
}

void Laser::move()
{
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase score
            game->score->increase(20);
            //removing from scene, but they still exist in memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //deleting to remove memory usage
            delete colliding_items[i];
            delete this;
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(Barrier))
        {
            switch(barrierhealth){
                case 0:
                    barrierhealth++;
                    scene()->removeItem(this);
                    delete this;
                    // put new picture
                    return;
                case 1:
                    scene()->removeItem(this);
                    delete this;
                    barrierhealth++;
                    //put new picture
                    return;
                case 2:
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
    }

    //moving Laser up
    setPos(x(), y() - 5);
    if (pos().y() + 50 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
