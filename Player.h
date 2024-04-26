#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    //spawning enemies
    void spawnEnemy();

    int enemySpacing;

    //Spawning Barriers
    void spawnBarrier();

public slots:
    void spawn_enemy_laser();
    void spawn_ufo();
private:
    int rand_enemy_type;
    QMediaPlayer *bullet_sound;
};

#endif // PLAYER_H
