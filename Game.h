#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QBoxLayout>
#include <QGraphicsScene>
#include <QDebug>
#include <QScreen>
#include <QLabel>
#include <QGraphicsView>
#include <QKeyEvent>

#include "Laser.h"
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Laser * laser;

    //Spawning Barriers
    void spawnBarrier();
    int barrierSpacing, barrierWidth, num_of_barriers;
    int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;


private:
    QLabel *gameScreen_Label, *header_Label;
    int GSWidthDivisor, GSHeightDivisor;
    int res_x, res_y;
    double gameScreenRatio, headerRatio;
};

#endif // GAME_H
