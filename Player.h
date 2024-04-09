#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"
#include "LaserEnemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "vector"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>


class Player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);

    bool shoot;
    void setPlayerShipWidth(int newPlayerShipWidth);

    std::vector<Enemy *> enemies;
public slots:
    void spawnEnemy();
    void spawnBarrier();
    void spawn_laser();
private:
    int test;
};

#endif // PLAYER_H
