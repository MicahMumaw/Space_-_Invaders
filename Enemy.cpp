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
        setPos(x() + ((gameScreenWidth - (100 * gameScreenWidth / 1700) - 11 * enemy_width - enemy_spacing * 10) / numberOfShifts), y());
    }
    else if (countup == false && count1 > 0 && count1 < numberOfShifts)
    {
        setPos(x() - ((gameScreenWidth - (100 * gameScreenWidth / 1700) - 11 * enemy_width - enemy_spacing * 10) / numberOfShifts), y());
    }
    //Shift down on the ends
    else if ((count1 == numberOfShifts) || (count1 == 0))
    {
        setPos(x(), y() + 15);
        speed += 1;
        shiftTimer->start(750 - (speed * 15));
    }
    if (pos().y() > scene()->height() - 200) //deletes enemies if they get to low, game over for the future
    {
        scene()->removeItem(this);
        delete this;
    }
}

int Enemy::getEnemy_type() const
{
    return enemy_type;
}

void Enemy::setEnemy_type(int newEnemy_type)
{
    enemy_type = newEnemy_type;
    if (enemy_type == 1)
    {
        if(alienoption==1){
            QPixmap enpic(":/images/ogal3.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }
        else if(alienoption==2){
            QPixmap enpic(":/images/rlal3.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }else{
            QPixmap enpic(":/images/pacal3.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }

    }
    else if (enemy_type == 2)
    {
        if(alienoption==1){
            QPixmap enpic(":/images/ogal2.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }
        else if(alienoption==2){
            QPixmap enpic(":/images/rlal2.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }else{
            QPixmap enpic(":/images/pacal2.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }
    }
    else
    {
        if(alienoption==1){
            QPixmap enpic(":/images/enemy1.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }
        else if(alienoption==2){
            QPixmap enpic(":/images/enemy2.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }else{
            QPixmap enpic(":/images/enemy3.png");
            enpic = enpic.scaled(QSize(enemy_width, enemy_height));
            setPixmap(enpic);
        }
    }
}
