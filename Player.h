#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"
#include "LaserEnemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include "vector"


class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn_player_laser();
private:
    int PlayerShipWidth;
    int sideSpacing, playableSpacing, enemyWidth, enemyHeight, enemySpacing;
};

#endif // PLAYER_H
