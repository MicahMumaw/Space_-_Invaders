#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>


class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event);

    bool shoot;
    void setPlayerShipWidth(int newPlayerShipWidth);

public slots:
    void spawn();

private:

};

#endif // PLAYER_H
