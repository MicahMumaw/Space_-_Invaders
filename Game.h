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

    //spawning enemies
    void spawnEnemy();
    std::vector<Enemy *> enemies;
    int enemyWidth, enemyHeight, enemySpacing;

    //Spawning Barriers
    void spawnBarrier();
    int barrierSpacing, barrierWidth, num_of_barriers;
    int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;

public slots:
    void spawn_enemy_laser();
private:
    QLabel *gameScreen_Label, *header_Label;
    int GSWidthDivisor, GSHeightDivisor;
    int res_x, res_y;
    double gameScreenRatio, headerRatio;
};

#endif // GAME_H
