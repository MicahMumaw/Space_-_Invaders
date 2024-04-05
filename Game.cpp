#include "Game.h"
#include "Player.h"
#include "ui_setup.h"
#include <QImage>
#include <QGraphicsScene>



#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include "Player.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>

Game::Game(QWidget *parent){

//Getting screen resolution. This is the entire screen the program is being ran on, not like window size.
    QScreen *screen = QGuiApplication::primaryScreen();
    QSize full_resolution = screen->geometry().size();
    qDebug() << "Screen resolution:" << full_resolution;


//Variable Definition
    res_x = full_resolution.width(), res_y = full_resolution.height();
    gameScreenRatio = 1.5;
    headerRatio = 0.07;
    headerWidth = res_x, headerHeight = res_x * headerRatio;
    gameScreenWidth = res_y * gameScreenRatio;
    gameScreenHeight = res_y - headerHeight;
    GSWidthDivisor = 100, GSHeightDivisor = 100;
    if (gameScreenWidth % GSWidthDivisor != 0)
    {
        gameScreenWidth -= gameScreenWidth % GSWidthDivisor;
    }
    if (gameScreenHeight % GSHeightDivisor != 0)
    {
        headerHeight += /*GSHeightDivisor - */gameScreenHeight % GSHeightDivisor;
        gameScreenHeight -= /*GSHeightDivisor - */gameScreenHeight % GSHeightDivisor;
    }
    qDebug() << gameScreenHeight;
    qDebug() << gameScreenWidth;


//Header Label
    header_Label = new QLabel("This is the header!", this);
    header_Label->setStyleSheet("background-color: rgb(150,150,150);");
    header_Label->setFixedSize(headerWidth, headerHeight);

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,gameScreenWidth,gameScreenHeight);
    setBackgroundBrush(QBrush(QImage(":/images/bullet2.png")));//Set background
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create the player
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setRect(0, 0, gameScreenWidth / (gameScreenWidth / 100), gameScreenHeight / 10);
    player->setPos(gameScreenWidth / 2 - player->rect().width() / 2, gameScreenHeight - player->rect().height());
    scene->addItem(player);

    QGraphicsView * view = new QGraphicsView(this);
    view->setFixedSize(gameScreenWidth, gameScreenHeight);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();

    //Spawning Enemy Grid
    player->spawn();


//Define Layouts - Horizontal
    QHBoxLayout *HLayout_Header = new QHBoxLayout();
    QHBoxLayout *HLayout_GameScreen = new QHBoxLayout();


//Define Layouts - Vertical
    QVBoxLayout *VLayout_Center = new QVBoxLayout();


//Create Horizontal Layouts

    HLayout_Header->addStretch();
    HLayout_Header->addWidget(header_Label);
    HLayout_Header->addStretch();

    HLayout_GameScreen->addStretch();
    HLayout_GameScreen->addWidget(view);
    HLayout_GameScreen->addStretch();


//Create Vertical Layouts
    VLayout_Center->setContentsMargins(0,0,0,0); //Ensures widgets to the edges of the screens
    VLayout_Center->setSpacing(0);
    VLayout_Center->addStretch();
    VLayout_Center->addLayout(HLayout_Header);
    VLayout_Center->addLayout(HLayout_GameScreen);
    VLayout_Center->addStretch();

    setLayout(VLayout_Center);


//Setting Full Screen
    showNormal();
    setWindowState(Qt::WindowMaximized);
    showFullScreen();
}

int Game::getGameScreenWidth(){
    return gameScreenWidth;
}
int Game::getGameScreenHeight(){
    return gameScreenHeight;
}

