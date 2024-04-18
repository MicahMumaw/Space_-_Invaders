#ifndef ENEMY_UFO_H
#define ENEMY_UFO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy_ufo: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy_ufo(QGraphicsItem * parent=0);
    void spawn_ufo_laser();

public slots:
    void move();
};

#endif // ENEMY_UFO_H
