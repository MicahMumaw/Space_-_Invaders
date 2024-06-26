#include "Laser.h"
#include "Barrier.h"
#include "Game.h"
#include "Enemy_ufo.h"

extern Game * game;

Laser::Laser(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    pixels_per_move_laser = 20;
    //assigns the color of laser the user picks to pixmap
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
    timer->start(10);

    enemy_hit_sound = new QMediaPlayer();
    enemy_hit_sound->setMedia(QUrl("qrc:/sounds/enemy_hit.wav"));
    enemy_hit_sound->setVolume(50);

    ufo_hit_sound = new QMediaPlayer();
    ufo_hit_sound->setMedia(QUrl("qrc:/sounds/ufo_hit.wav"));
    ufo_hit_sound->setVolume(110);
}

void Laser::move()
{
    QList < QGraphicsItem * > colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) // if the laser hits an enemy
        {
            enemy_hit_sound->play();
            for (int x = 0; x <= int(enemies.size()); x++)
            {
                if (colliding_items[i] == enemies[x])
                {
                    Enemy *randomObject = enemies[x];
                    if (randomObject->getEnemy_type() == 3)
                    {
                        game->score->increase(10);
                    }
                    else if (randomObject->getEnemy_type() == 2)
                    {
                        game->score->increase(20);
                    }
                    else if (randomObject->getEnemy_type() == 1)
                    {
                        game->score->increase(40);
                    }
                    enemies.erase(enemies.begin() + x);
                }
            }
            lasers.pop_back();
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
            lasers.pop_back();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Enemy_ufo))
        {
            lasers.pop_back();
            ufo_hit_sound->play();
            game->score->increase(100);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //moving Laser up
    setPos(x(), y() - pixels_per_move_laser);
    if (pos().y() + 50 < 0)
    {
        lasers.pop_back();
        scene()->removeItem(this);
        delete this;
    }
}
