#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent=0);
    void spawn_enemy2_laser();
    int getEnemy2_type() const;
    void setEnemy2_type(int newEnemy_type);

public slots:
    void move();
private:
    QTimer * shiftTimer;
    bool countup;
    int count1, numberOfShifts;
    int speed;
    int enemy_type;
};

#endif // ENEMY2_H
