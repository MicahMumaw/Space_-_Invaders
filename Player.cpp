#include "Player.h"
#include "Game.h"
#include "Laser.h"
#include "LaserEnemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Barrier.h"

#include "qdebug.h"
#include "windows.h"

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    enemySpacing = 25;
    shoot = true;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
//Arrow Keys
    case Qt::Key_Left:
        if (pos().x() > 0)
        {
            setPos(x() - 10, y());
        }
        break;
    case Qt::Key_Right:
        if (pos().x()-50 < scene()->width()) // NEED TO FIX
        {
            setPos(x() + 10, y());
        }
        break;
//"WASD" Keys
    case Qt::Key_A:
        if (pos().x()-50 > 0)
        {
            setPos(x() - 10, y());
        }
        break;
    case Qt::Key_D:
        if (pos().x()  < scene()->width())
        {
            setPos(x() + 10, y());
        }
        break;
    case Qt::Key_Escape:
        exit(0);
        break;
//Shooting with space bar
    case Qt::Key_Space:
        if(shoot)
        {
            spawn_player_laser();
            QTimer::singleShot(1000, this, &Player::setShoot);
        }
        shoot = false;

        break;
    }
}

void Player::spawnEnemy()
{
    for (int x = 0; x <= 10; x++)
    {
        for (int y = 1; y <= 5; y++)
        {
            Enemy * enemy = new Enemy();
            scene()->addItem(enemy);
            enemy->setPos(enemy_width + x * enemySpacing + x * enemy_width, y * (enemySpacing + enemy_height - 15));
            enemies.push_back(enemy);
        }
    }
}


void Player::spawnBarrier()
{
    for (int j = 0; j <= 3; j++)
    {
        for(int x = 0; x <= (barrier_total_width / barrier_side_length); x++)
        {
            for (int y = 0; y <= (barrier_total_height / barrier_side_length); y++)
            {
                Barrier * barrier = new Barrier();
                scene()->addItem(barrier);
                barrier->setPos(barrier_spacing + j * barrier_spacing + j * barrier_total_width + x * barrier_side_length,
                               (7 * gameScreenHeight / 9) + y * barrier_side_length);
            }
        }
    }
}

void Player::spawn_enemy_laser()
{
    int randomIndex = rand() % enemies.size();
    Enemy *randomObject = enemies[randomIndex];
    LaserEnemy * laserenemy = new LaserEnemy();
    laserenemy->setPos(randomObject->pos().x() + 22, randomObject->pos().y());
    scene()->addItem(laserenemy);
}

void Player::spawn_player_laser()
{
    Laser * laser = new Laser();
    laser->setPos(x() + (player_width / 2 - laser_width / 2), gameScreenHeight - player_height - laser_height);
    scene()->addItem(laser);
}

void Player::player_laser_cooldown()
{
    cooldown_timer = new QTimer();
    QObject::connect(cooldown_timer, SIGNAL(timeout()), this, SLOT(setShoot(true)));
    cooldown_timer->start(1000);
}

void Player::setShoot()
{
    shoot = true;
}


