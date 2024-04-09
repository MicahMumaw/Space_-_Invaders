#include "Player.h"
#include "Barrier.h"
#include "Enemy.h"
#include "Game.h"
#include "Laser.h"
#include "vector"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

extern Game * game;

Player::Player()
{
    shoot = true;
    test = 8008135;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
//Arrow Keys
    case Qt::Key_Left:
        if (pos().x() > 0)
        {
            setPos(x() - 20, y());
        }
        break;
    case Qt::Key_Right:
        if (pos().x() + this->rect().width() < scene()->width())
        {
            setPos(x() + 20, y());
        }
        break;
//"WASD" Keys
    case Qt::Key_A:
        if (pos().x() > 0)
        {
            setPos(x() - 20, y());
        }
        break;
    case Qt::Key_D:
        if (pos().x() + this->rect().width() < scene()->width())
        {
            setPos(x() + 20, y());
        }
        break;
    case Qt::Key_Escape:
        exit(0);
        break;
//Shooting with space bar
    case Qt::Key_Space:
        //Create a laser
        Laser * laser = new Laser();
        laser->setPos(x() + 45, y());
        scene()->addItem(laser);
        break;

    }
}

void Player::spawnBarrier()
{
    for (int x = 0; x <= 3; x++)
    {
        Barrier * barrier = new Barrier();
        scene()->addItem(barrier);
        barrier->setPos((barrier->getBarrierSpacing()) + x * (barrier->getBarrierSpacing()) + x * (barrier->getBarrierWidth()), (7 * 900 / 9));
    }

}

void Player::spawnEnemy()
{
    //Create an Enemy
    for (int x = 1; x <= 11; x++)
    {
        for (int y = 1; y <= 5; y++)
        {
            Enemy * enemy = new Enemy();
            scene()->addItem(enemy);
            enemy->setPos(x * (scene()->width() / 12), y * 60);
            enemies.push_back(enemy);
        }
    }
}

void Player::spawn_laser()
{
    int randomIndex = rand() % enemies.size();
    Enemy *randomObject = enemies[randomIndex];
    //randomObject->setPos(100, 100);
}
