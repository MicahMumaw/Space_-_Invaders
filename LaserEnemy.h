#ifndef LASERENEMY_H
#define LASERENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class LaserEnemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    LaserEnemy(QGraphicsItem * parent = 0);
public slots:
    void move();
};
#endif // LASERENEMY_H
