#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    //spawning enemies
    void spawnEnemy();
    std::vector<Enemy *> enemies;
    int enemyWidth, enemyHeight, enemySpacing;

public slots:
    void spawn_enemy_laser();
    void spawn_player_laser();
    void player_laser_cooldown();
private:
    QTimer *cooldown_timer;
};

#endif // PLAYER_H
