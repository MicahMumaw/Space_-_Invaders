#include "Laser.h"
#include "Barrier.h"
#include "Game.h"
#include "Enemy_ufo.h"

extern Game * game;

Laser::Laser(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    pixels_per_move_laser = 15;
    //Assign pixmap to item
    if (laseroption==1){
        QPixmap bullet_pixmap(":/images/bullet.png");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }else if(laseroption ==2){
        QPixmap bullet_pixmap(":/images/redbullet.png");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }
    else{
        QPixmap bullet_pixmap(":/images/greenbullet.jpg");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(15);
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
            //qDebug() << colliding_items[i];
            //Enemy *randomObject = &colliding_items[i];
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
            //removing from scene, but they still exist in memory
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //deleting to remove memory usage
            delete colliding_items[i];
            delete this;
            return;
        }
//        if (typeid(*(colliding_items[i])) == typeid(Enemy_ufo))
//        {
//            //increase score
//            game->score->increase(50);
//            //removing from scene, but they still exist in memory
//            scene()->removeItem(colliding_items[i]);
//            scene()->removeItem(this);

//            //deleting to remove memory usage
//            delete colliding_items[i];
//            delete this;
//            return;
//        }
    }

    //moving Laser up
    setPos(x(), y() - pixels_per_move_laser);
    if (pos().y() + 50 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
