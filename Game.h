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
#include "LaserEnemy.h"
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"

extern int res_x, res_y;
extern int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;
extern int barrierSpacing, barrierWidth, num_of_barriers;
extern int enemy_width, enemy_height, enemy_spacing;
extern int laser_width, laser_height;
extern int barrier_total_width, barrier_total_height, barrier_spacing, barrier_side_length, barrier_width, barrier_height;
extern int player_width, player_height;
extern int playeroption, alienoption, laseroption;
extern int score1, score2,score3,score4;
extern int loss, play_again, play_again_temp;
extern bool left_shift, right_shift, down_shift;
extern int level_increment;
extern QString name1,name2,name3,name4;
extern std::vector<Enemy *> enemies;
extern std::vector<Laser *> lasers;

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    LaserEnemy * laserenemy;

private:
    QLabel *gameScreen_Label, *header_Label;
    int GSWidthDivisor, GSHeightDivisor;
    double gameScreenRatio, headerRatio;
};

#endif // GAME_H
