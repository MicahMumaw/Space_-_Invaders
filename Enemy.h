#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();

private:
    bool countup;
    int count1, numberOfShifts;
};

#endif // ENEMY_H
