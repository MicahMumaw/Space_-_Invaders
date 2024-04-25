#ifndef LASER_H
#define LASER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Laser: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Laser(QGraphicsItem * parent = 0);

public slots:
    void move();
private:
    int pixels_per_move_laser;
    QMediaPlayer * enemy_hit_sound;
};

#endif // LASER_H
