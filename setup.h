#ifndef SETUP_H
#define SETUP_H

#include <QDialog>
#include <QBoxLayout>
#include <QGraphicsScene>
#include <QDebug>
#include <QScreen>
#include <QLabel>
#include <QGraphicsView>

#include "Player.h"
#include "Enemy.h"
#include "Laser.h"

namespace Ui {
class Setup;
}

class Setup : public QDialog
{
    Q_OBJECT

public:
    explicit Setup(QWidget *parent = nullptr);
    ~Setup();

    //GRAPHICS SCENE
    QGraphicsScene * scene;

    int res_x, res_y;
    double gameScreenRatio, headerRatio;
    int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;



private:
    Ui::Setup *ui;

    QLabel *gameScreen_Label, *header_Label;
};

#endif // SETUP_H
