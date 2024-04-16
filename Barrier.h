#ifndef BARRIER_H
#define BARRIER_H

#include <QGraphicsRectItem>
#include <QObject>


class Barrier: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Barrier();

};
#endif // BARRIER_H
