#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy();

    int getEnemyWidth() const;
    void setEnemyWidth(int newEnemyWidth);

    int getEnemyHeight() const;
    void setEnemyHeight(int newEnemyHeight);

    void spawn_enemy_laser();
public slots:
    void move();

private:
    bool countup;
    int count1, numberOfShifts;
    int enemyWidth, enemyHeight;
};

#endif // ENEMY_H
