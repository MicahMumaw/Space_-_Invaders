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
    pixels_per_move_enemy_laser = 3;
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
        QPixmap bullet_pixmap(":/images/greenbullet.png");
        bullet_pixmap  = bullet_pixmap.scaled(laser_width, laser_height);
        setPixmap(QPixmap(bullet_pixmap));
    }
    setPos(x() + 100, 100);

    //connect movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(15);
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

                    return;
                case 2:
                    //decrease health
                    game->health->decrease();
                    scene()->removeItem(this);
                    delete this;

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
                    scorecheck(); // doing highscore stuff
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
//    if (num_enemy_lasers_shot >= 16)
//    {
//        pixels_per_move_enemy_laser = 3;
//    }
    setPos(x(), y() + pixels_per_move_enemy_laser);
    if (pos().y() > gameScreenHeight)
    {
        scene()->removeItem(this);
        delete this;
    }
}
void LaserEnemy::scorecheck(){
    EndScreen *endscreen = new EndScreen();
    endscreen->show();
    game->hide();

}


