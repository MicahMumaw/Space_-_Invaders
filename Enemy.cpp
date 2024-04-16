#include "Enemy.h"
#include "qgraphicsscene.h"

#include <QTimer>
#include <stdlib.h> //rand()
#include <QDebug>
#include "Game.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int

extern Game * game;


Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Variable definition
    countup = true;
    count1 = 1;
    numberOfShifts = 20;
    speed = 0;
    //Enemy pixmap creation
    QPixmap enpic(":/images/enemy1.png");
    QPixmap smallpic = enpic.scaled(QSize(enemy_width, enemy_height));
    setPixmap(smallpic);

    //move timer
    shiftTimer = new QTimer();
    connect(shiftTimer, SIGNAL(timeout()), this, SLOT(move()));
    shiftTimer->start(500 + (speed * 25));
}

void Enemy::move()
{    
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
        setPos(x() + (325 / numberOfShifts), y());
    }
    else if (countup == false && count1 > 0 && count1 < numberOfShifts)
    {
        setPos(x() - (325 / numberOfShifts), y());
    }
    //Shift down on the ends
    else if ((count1 == numberOfShifts) || (count1 == 0))
    {
        setPos(x(), y() + 15);
        speed += 1;
        shiftTimer->start(500 + (speed * 25));
    }
    if (pos().y() > scene()->height() - 200) //deletes enemies if they get to low, game over for the future
    {
        scene()->removeItem(this);
        delete this;
    }
}
