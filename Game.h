#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QBoxLayout>
#include <QGraphicsScene>
#include <QDebug>
#include <QScreen>
#include <QLabel>
#include <QGraphicsView>
#include "Player.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget * parent = 0);
    //GRAPHICS SCENE
    QGraphicsScene * scene;
    Player * player;

    int getGameScreenWidth();
    int getGameScreenHeight();
private:
    QLabel *gameScreen_Label, *header_Label;

    int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;
    int GSWidthDivisor, GSHeightDivisor;
    int res_x, res_y;
    double gameScreenRatio, headerRatio;
};

#endif // GAME_H
