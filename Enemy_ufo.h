#ifndef ENEMY_UFO_H
#define ENEMY_UFO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Enemy_ufo: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy_ufo(QGraphicsItem * parent=0);
public slots:
    void move();
private:
    QMediaPlayer *ufo_sound;
};

#endif // ENEMY_UFO_H
