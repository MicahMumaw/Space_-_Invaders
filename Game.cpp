#include "Game.h"
#include "Player.h"
#include "Barrier.h"
#include "Enemy.h"
#include "Health.h"
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

Game::Game(QWidget *parent)
{
//Getting screen resolution. This is the entire screen the program is being ran on, not like window size.
    QScreen *screen = QGuiApplication::primaryScreen();
    QSize full_resolution = screen->geometry().size();
    qDebug() << "Screen resolution:" << full_resolution;

//Variable Definition
    //res_x = full_resolution.width(), res_y = full_resolution.height(); //FOR USE ON CHEKA'S COMPUTER
    res_x = 1366, res_y = 768; //FOR USE ELSE WHERE
    gameScreenRatio = 1.5;
    headerRatio = 0.07;
    headerWidth = res_x, headerHeight = res_x * headerRatio;
    gameScreenWidth = res_y * gameScreenRatio;
    gameScreenHeight = res_y - headerHeight;
    GSWidthDivisor = 100, GSHeightDivisor = 100;

    if (gameScreenWidth % GSWidthDivisor != 0) //Making sure gamescreen dimensions are divisible by 100 because I want to :)
    {
        gameScreenWidth += GSWidthDivisor - gameScreenWidth % GSWidthDivisor;
    }
    if (gameScreenHeight % GSHeightDivisor != 0)
    {
        headerHeight -= GSHeightDivisor - gameScreenHeight % GSHeightDivisor;
        gameScreenHeight += GSHeightDivisor - gameScreenHeight % GSHeightDivisor;
    }

    //Barrier Variables
    num_of_barriers = 4;
    barrierWidth = gameScreenWidth / 11;
    barrierSpacing = (gameScreenWidth - barrierWidth * num_of_barriers) / 5 ;
    qDebug() << barrierSpacing;

    //Enemy Variables
    enemyWidth = 50, enemyHeight = 50, enemySpacing = 25;

    qDebug() << gameScreenWidth;
    qDebug() << gameScreenHeight;


//Header Label
    header_Label = new QLabel("Space Invaders",this);
    header_Label->setStyleSheet("background-color: rgb(0,0,0);font: italic 50pt \"Harlow Solid Italic\";color:rgb(255, 255, 255)");
    header_Label->setFixedSize(headerWidth, headerHeight);
    header_Label->setAlignment(Qt::AlignCenter);

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
    player->setRect(0, 0, gameScreenWidth / 20, gameScreenHeight / 10);
    player->setPos(gameScreenWidth / 2 - player->rect().width() / 2, gameScreenHeight - player->rect().height());
    scene->addItem(player);

    QGraphicsView * view = new QGraphicsView(this);
    view->setFixedSize(gameScreenWidth, gameScreenHeight);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();

    //creating and adding Enemies and Barriers
    spawnEnemy();
    spawnBarrier();

    //creating and adding score and health
    score = new Score();
    score->setPos((gameScreenWidth / 2) / 3, 0);
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemy lasers
    QTimer * timer_Enemy_lasers = new QTimer();
    QObject::connect(timer_Enemy_lasers, SIGNAL(timeout()), this, SLOT(spawn_enemy_laser()));
    timer_Enemy_lasers->start(1000);
    spawn_enemy_laser();
    _sleep(1);
    spawn_enemy_laser();
    _sleep(1);
    spawn_enemy_laser();

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

    move((1920 - 1366)/2, (1080 - 768)/2); //USE TO CENTER WHILE TESTING

//Setting Full Screen
    showNormal();
    //setWindowState(Qt::WindowMaximized);
    //showFullScreen();
}

void Game::spawnEnemy()
{
    for (int x = 0; x <= 10; x++)
    {
        for (int y = 1; y <= 5; y++)
        {
            Enemy * enemy = new Enemy();
            scene->addItem(enemy);
            enemy->setPos(enemyWidth + x * enemySpacing + x * enemyWidth, y * (enemySpacing + enemyHeight - 15));
            enemies.push_back(enemy);
        }
    }
}

void Game::spawnBarrier()
{
    for (int x = 0; x <= 3; x++)
    {
        Barrier * barrier = new Barrier();
        scene->addItem(barrier);
        barrier->setPos(barrierSpacing + x * barrierSpacing + x * barrierWidth, (7 * gameScreenHeight / 9));
    }
}

void Game::spawn_enemy_laser()
{
    int randomIndex = rand() % enemies.size();
    Enemy *randomObject = enemies[randomIndex];
    randomObject->deleteLater();

    LaserEnemy * laserenemy = new LaserEnemy();
    laserenemy->setPos(randomObject->pos().x() + 22, randomObject->pos().y() + 50);
    scene->addItem(laserenemy);
}
