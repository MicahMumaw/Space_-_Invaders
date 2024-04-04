#include "Laser.h"
#include "setup.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <QList>

Laser::Laser()
{
    //drew the rectangle
    setRect(0,0,10, 50);

    //connect stuff
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void Laser::move()
{
    //If Laser collides with enemy, destroy both
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
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
    setPos(x(), y() - 10);
    if (pos().y() + this->rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
