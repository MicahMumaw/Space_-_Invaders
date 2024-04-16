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

extern int res_x, res_y;
extern int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;
extern int barrierSpacing, barrierWidth, num_of_barriers;
extern int enemy_width, enemy_height;
extern int laser_width, laser_height;
extern int barrier_total_width, barrier_total_height, barrier_spacing, barrier_side_length, barrier_width, barrier_height;
extern int player_width, player_height;

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Laser * laser;
    //Barrier * barrier;

private:
    QLabel *gameScreen_Label, *header_Label;
    int GSWidthDivisor, GSHeightDivisor;
    double gameScreenRatio, headerRatio;
};

#endif // GAME_H
