#include "Player.h"
#include "Barrier.h"
#include "Enemy.h"
#include "Game.h"
#include "Laser.h"
#include "vector"
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

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
        spawn_player_laser();
        break;
    }
}

void Player::spawn_player_laser()
{
    Laser * laser = new Laser();
    laser->setPos(x() + 27, y());
    scene()->addItem(laser);
}
