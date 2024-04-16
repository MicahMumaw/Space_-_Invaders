#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    void spawn_enemy_laser();
public slots:
    void move();
private:
    QTimer * shiftTimer;
    bool countup;
    int count1, numberOfShifts;
    int speed;
};

#endif // ENEMY_H
