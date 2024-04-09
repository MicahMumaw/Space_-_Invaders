#ifndef LASER_H
#define LASER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Laser: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Laser(QGraphicsItem * parent = 0);
public slots:
    void move();
};

#endif // LASER_H
