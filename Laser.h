#ifndef LASER_H
#define LASER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Laser: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Laser(QGraphicsItem * parent = 0);
public slots:
    // "public slots" means it can be connected to a signal
    void move();
};


#endif // LASER_H
