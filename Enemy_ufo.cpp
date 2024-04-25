#include "Enemy_ufo.h"
#include "qgraphicsscene.h"
#include <QTimer>
#include "Game.h"

Enemy_ufo::Enemy_ufo(QGraphicsItem *parent)
{
    QPixmap ufo_pic(":/images/ufo.png");
    ufo_pic = ufo_pic.scaled(QSize(enemy_width * 2, enemy_width));
    setPixmap(ufo_pic);
    setPos(enemy_width * 2.1, enemy_height * 1.2);
//move timer
    QTimer * shiftTimer = new QTimer();
    connect(shiftTimer, SIGNAL(timeout()), this, SLOT(move()));
    shiftTimer->start(13);

    ufo_sound = new QMediaPlayer();
    ufo_sound->setMedia(QUrl("qrc:/sounds/ufo.mp3"));
    ufo_sound->setVolume(100);
    ufo_sound->play();
}

void Enemy_ufo::move()
{
    if (pos().x() > gameScreenWidth - (enemy_width * 2.1))
    {
        scene()->removeItem(this);
        delete this;
    }
    else
    {
        setPos(x() + 6, y());
    }
}

