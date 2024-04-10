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
public slots:
    void spawn_player_laser();
private:
    int PlayerShipWidth;
    int sideSpacing, playableSpacing, enemyWidth, enemyHeight, enemySpacing;
};

#endif // PLAYER_H
