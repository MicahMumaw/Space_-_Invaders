#include "LaserEnemy.h"
#include "Barrier.h"
#include "Game.h"
#include "qgraphicsscene.h"
#include "ui_endscreen.h"
#include "endscreen.h"
#include <QInputDialog>

#include <QTimer>
#include <QList>

extern Game * game;

LaserEnemy::LaserEnemy(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    pixels_per_move_enemy_laser = 4;
    //Assign pixmap to item
    if (laseroption==1)
    {
        QPixmap bullet_pixmap(":/images/bullet.png");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }
    else if(laseroption ==2)
    {
        QPixmap bullet_pixmap(":/images/redbullet.png");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }
    else
    {
        QPixmap bullet_pixmap(":/images/greenbullet.jpg");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }
    setPos(x() + 100, 100);

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);

    hit_sound = new QMediaPlayer();
    hit_sound->setMedia(QUrl("qrc:/sounds/player_hit.mp3"));
    hit_sound->setVolume(12);
}

void LaserEnemy::move()
{
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            hit_sound->play();
            switch(game->health->getHealth()){
                case 3:
                    //decrease health
                    game->health->decrease(); // decreases players health
                    scene()->removeItem(this); // removes the laser image
                    delete this; // deleted it from memory
                    return;
                case 2:
                    game->health->decrease();
                    scene()->removeItem(this);
                    delete this;
                    return;
                case 1:
                    game->health->decrease();
                    //removing from scene, but they still exist in memory
                    scene()->removeItem(colliding_items[i]); // removes ship from screen
                    scene()->removeItem(this); //removes laser from screen
                    //deleting to remove memory usage
                    delete colliding_items[i];
                    delete this;
                    scorecheck(); //ends up taking them to endscreen
                    return;
                default:
                    return;

            }
        }
        if (typeid(*(colliding_items[i])) == typeid(Barrier))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(), y() + pixels_per_move_enemy_laser);
    if (pos().y() > gameScreenHeight)
    {
        scene()->removeItem(this);
        delete this;
    }
}
void LaserEnemy::scorecheck(){ // will show the end screen
    EndScreen *endscreen = new EndScreen();
    endscreen->show();
    game->hide();

}


