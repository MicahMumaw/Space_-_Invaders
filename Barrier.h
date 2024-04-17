#ifndef BARRIER_H
#define BARRIER_H

#include <QGraphicsRectItem>
#include <QObject>


class Barrier: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Barrier();
    int barrierhealth;
    int getBarrierhealth() const;
};
#endif // BARRIER_H
