#include "Enemy.h"
#include "LaserEnemy.h"
#include <QTimer>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //Variable definition
    countup = true;
    count1 = 1;
    numberOfShifts = 20;
    speed = 500;

    //move timer
    shiftTimer = new QTimer();
    connect(shiftTimer, SIGNAL(timeout()), this, SLOT(move()));
    shiftTimer->start(speed);
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
        speed *= 0.95;
        shiftTimer->start(speed);
    }
   if (pos().y() > gameScreenHeight - (220 * gameScreenHeight / 768)) //deletes enemies if they get to low, game over for the future
    {
        if (loss == 0)
        {
            qDebug() << "test";
            loss = 1;
            game->laserenemy->scorecheck();
            delete game;
        }
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
