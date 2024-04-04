#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);

    bool shoot;
public slots:
    void spawn();
};

#endif // PLAYER_H
