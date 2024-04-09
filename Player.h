#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"
#include "LaserEnemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>


class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);

    bool shoot;
    void setPlayerShipWidth(int newPlayerShipWidth);

    std::vector<Enemy> enemies;
public slots:
    void spawnEnemy();
    void spawnBarrier();
    void spawn_laser();
private:
    int test;
};

#endif // PLAYER_H
