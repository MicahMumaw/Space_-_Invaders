#include "Enemy.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand() -> really large int
#include <QDebug>
#include "Game.h"

extern Game * game;

Enemy::Enemy()
{
    countup = true;
    count1 = 0;
    numberOfShifts = 8;

    //draw the rectangle
    setRect(0, 0, 50, 50);

    //connect stuff
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(500);
}

void Enemy::move()
{
    //move Enemy down
//    qDebug() << game->getGameScreenHeight(); // this is a problem, get function is just causing a crash when called


    //counting up and down
        if (countup)
        {
            if (count1 >= numberOfShifts - 1)
            {
                countup = false;
            }
            count1++;
        }
        else
        {
            if (count1 <= 1)
            {
                countup = true;
            }
            count1--;
        }

        //shift left and right
        if (countup == true && count1 < numberOfShifts && count1 > 0)
        {
            setPos(x() + 15, y());
//            enemyGridPosX += gameScreenWidth / (numberOfShifts * 5);
        }
        else if (countup == false && count1 > 0 && count1 < numberOfShifts)
        {
            setPos(x() - 15, y());
        }

        //Shift down on the ends
        else if ((count1 == numberOfShifts) || (count1 == 0))
        {
            setPos(x(), y() + 50);
        }

        if (pos().y() > scene()->height() - 200)
        {
            scene()->removeItem(this);
            delete this;
        }
}
