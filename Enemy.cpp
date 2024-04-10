#include "Enemy.h"
#include "LaserEnemy.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand()
#include <QDebug>
#include "Game.h"

extern Game * game;

Enemy::Enemy()
{
    countup = true;
    count1 = 0;
    numberOfShifts = 20;

    //draw the rectangle
    setRect(0, 0, 50, 50);

    //move timer
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(500);
}

void Enemy::move()
{    
//    //counting up and down
//    if (countup)
//    {
//        if (count1 >= numberOfShifts - 1)
//        {
//            countup = false;
//        }
//        count1++;
//    }
//    else
//    {
//        if (count1 <= 1)
//        {
//            countup = true;
//        }
//        count1--;
//    }
//    //shift left and right
//    if (countup == true && count1 < numberOfShifts && count1 > 0)
//    {
//        setPos(x() + (325 / numberOfShifts), y());
//    }
//    else if (countup == false && count1 > 0 && count1 < numberOfShifts)
//    {
//        setPos(x() - (325 / numberOfShifts), y());
//    }
//    //Shift down on the ends
//    else if ((count1 == numberOfShifts) || (count1 == 0))
//    {
//        setPos(x(), y() + 15);
//    }
//    if (pos().y() > scene()->height() - 200)
//    {
//        scene()->removeItem(this);
//        delete this;
//    }
}

int Enemy::getEnemyHeight() const
{
    return enemyHeight;
}

void Enemy::setEnemyHeight(int newEnemyHeight)
{
    enemyHeight = newEnemyHeight;
}

int Enemy::getEnemyWidth() const
{
    return enemyWidth;
}

void Enemy::setEnemyWidth(int newEnemyWidth)
{
    enemyWidth = newEnemyWidth;
}


