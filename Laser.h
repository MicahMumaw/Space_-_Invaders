#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>

class Laser: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Laser();
public slots:
    // "public slots" means it can be connected to a signal
    void move();
};


#endif // LASER_H
