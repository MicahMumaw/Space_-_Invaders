#include "Player.h"
#include "setup.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Player::Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
//Arrow Keys
    case Qt::Key_Left:
        if (pos().x() > 0)
        {
            setPos(x() - 15, y());
        }
        break;
    case Qt::Key_Right:
        if (pos().x() + this->rect().width() < scene()->width())
        {
            setPos(x() + 15, y());
        }
        break;
//"WASD" Keys
    case Qt::Key_A:
        if (pos().x() > 0)
        {
            setPos(x() - 15, y());
        }
        break;
    case Qt::Key_D:
        if (pos().x() + this->rect().width() < scene()->width())
        {
            setPos(x() + 15, y());
        }
        break;
//Shooting with space bar
    case Qt::Key_Space:
        //Create a laser
        Laser * laser = new Laser();
        laser->setPos(x(), y());
        scene()->addItem(laser);
        break;
    }
}

void Player::spawn()
{
    //Create an Enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
