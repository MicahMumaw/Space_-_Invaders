#include "Player.h"
#include "Enemy_ufo.h"
#include "Game.h"
#include "Laser.h"
#include "LaserEnemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Barrier.h"
#include "qdebug.h"
#include "windows.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/sounds/laser.mp3"));
    bullet_sound->setVolume(100);

    rand_enemy_type = 1;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
//Arrow Keys
    case Qt::Key_Left:
        if (pos().x() > (15 * gameScreenWidth / 1366))
        {
            setPos(x() - (15 * gameScreenWidth / 1366), y());
        }
        break;
    case Qt::Key_Right:
        if (pos().x() < gameScreenWidth - player_width - (15 * gameScreenWidth / 1366))
        {
            setPos(x() + (15 * gameScreenWidth / 1366), y());
        }
        break;
//"WASD" Keys
    case Qt::Key_A:
        if (pos().x() > (15 * gameScreenWidth / 1366))
        {
            setPos(x() - (15 * gameScreenWidth / 1366), y());
        }
        break;
    case Qt::Key_D:
        if (pos().x() < gameScreenWidth - player_width - (15 * gameScreenWidth / 1366))
        {
            setPos(x() + (15 * gameScreenWidth / 1366), y());
        }
        break;
    case Qt::Key_Escape:
        exit(0);
        break;
//Shooting with space bar
    case Qt::Key_Space:
        qDebug() << lasers.size();
        if (lasers.size() == 0)
        {
            Laser * laser = new Laser();
            laser->setPos(x() + (player_width / 2 - laser_width / 2), gameScreenHeight - player_height - laser_height);
            scene()->addItem(laser);
            //spawn_player_laser();
            lasers.push_back(laser);
            bullet_sound->play();
        }
        break;
    }
}

void Player::spawnEnemy()
{
    int a1,a2,a3;
    if (alienoption==1){
        a1=3;
        a2=2;
        a3=alienoption;
    }else if (alienoption==2){
        a1=3;
        a2=1;
        a3=alienoption;
    }
    else{
        a1=1;
        a2=2;
        a3=alienoption;
    }
    for (int y = 1; y <= 5; y++)
    {
        switch(y){
            case 1:
            rand_enemy_type= a3;
            break;
            case 2:
            case 3:
            rand_enemy_type= a2;
            break;
            case 4:
            case 5:
                rand_enemy_type= a1;
                break;
        }

        for (int x = 0; x <= 9; x++)
        {
            Enemy * enemy = new Enemy();
            enemy->setEnemy_type(rand_enemy_type);
            scene()->addItem(enemy);
            enemy->setPos((100 * gameScreenWidth / 1700) + enemy_width * 0.5 + x * enemy_spacing + x * enemy_width,
                           enemy_spacing + y * (enemy_spacing + enemy_height - 10));
            enemies.push_back(enemy);
        }
    }
}

void Player::spawnBarrier()
{
    for (int j = 0; j <= 3; j++)
    {
        for(int x = 1; x <= (barrier_total_width / barrier_width); x++)
        {
            for (int y = 1; y <= (barrier_total_height / barrier_height); y++)
            {
                Barrier * barrier = new Barrier();
                scene()->addItem(barrier);
                barrier->setPos(barrier_spacing + j * barrier_spacing + j * barrier_total_width + x * barrier_width,
                               (7 * gameScreenHeight / 9) + y * barrier_height);
            }
        }
    }
}

void Player::spawn_enemy_laser()
{
    if (enemies.size() == 0)
    {
        level_increment += 1;
        spawnEnemy();
        game->health->increase();
    }
    else
    {
        int randomIndex = rand() % enemies.size();
        Enemy *randomObject = enemies[randomIndex];
        if(randomObject->pos().x() > 15)
        {
            LaserEnemy * laserenemy = new LaserEnemy();
            laserenemy->setPos(randomObject->pos().x() + 22, randomObject->pos().y() + enemy_height);
            scene()->addItem(laserenemy);
        }
    }
}

void Player::spawn_ufo()
{
    Enemy_ufo * enemy_ufo = new Enemy_ufo();
    scene()->addItem(enemy_ufo);
    enemy_ufo->setPos(-100, 50);
}
