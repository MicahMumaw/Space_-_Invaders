#include "Player.h"
#include "Laser.h"
#include "LaserEnemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

#include "windows.h"

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
//Enemy Variables
    enemyWidth = 50, enemyHeight = 50, enemySpacing = 25;
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
        spawn_player_laser();
        player_laser_cooldown();
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
            enemy->setPos(enemyWidth + x * enemySpacing + x * enemyWidth, y * (enemySpacing + enemyHeight - 15));
            enemies.push_back(enemy);
        }
    }
}

void Player::spawn_enemy_laser()
{
    int randomIndex = rand() % enemies.size();
    Enemy *randomObject = enemies[randomIndex];
    LaserEnemy * laserenemy = new LaserEnemy();
    laserenemy->setPos(randomObject->pos().x() + 22, randomObject->pos().y() + 50);
    scene()->addItem(laserenemy);
}

void Player::spawn_player_laser()
{
    Laser * laser = new Laser();
    laser->setPos(x() + 27, y());
    scene()->addItem(laser);
}

void Player::player_laser_cooldown()
{
    cooldown_timer = new QTimer();
    QObject::connect(cooldown_timer, SIGNAL(timeout()), this, SLOT(spawn_enemy_laser()));
    cooldown_timer->start(1000);
}


