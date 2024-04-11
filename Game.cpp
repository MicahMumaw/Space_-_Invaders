#include "Game.h"
#include "LaserEnemy.h"
#include "Barrier.h"
#include "ui_setup.h"

Game::Game(QWidget *parent)
{
//Getting screen resolution. This is the entire screen the program is being ran on, not like window size.
    QScreen *screen = QGuiApplication::primaryScreen();
    QSize full_resolution = screen->geometry().size();
    qDebug() << "Screen resolution:" << full_resolution;

//Variable Definition
    res_x = full_resolution.width(), res_y = full_resolution.height(); //FOR USE ON CHEKA'S COMPUTER
    //res_x = 1366, res_y = 768; //FOR USE ELSE WHERE
    gameScreenRatio = 1.5;
    headerRatio = 0.07;
    headerWidth = res_x, headerHeight = res_x * headerRatio;
    gameScreenWidth = res_y * gameScreenRatio;
    gameScreenHeight = res_y - headerHeight;
    GSWidthDivisor = 100, GSHeightDivisor = 100;
//Making sure gamescreen dimensions are divisible by 100 because I want to :)
    if (gameScreenWidth % GSWidthDivisor != 0)
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
//Enemy Variables
    enemyWidth = 50, enemyHeight = 50, enemySpacing = 25;

//Header Label
    header_Label = new QLabel("Space Invaders",this);
    header_Label->setStyleSheet("background-color: rgb(0,0,0);font: italic 50pt \"Harlow Solid Italic\";color:rgb(255, 255, 255)");
    header_Label->setFixedSize(headerWidth, headerHeight);
    header_Label->setAlignment(Qt::AlignCenter);

// create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,gameScreenWidth,gameScreenHeight);
    setBackgroundBrush(QBrush(QColor::fromRgb(0,0,0)));//Set background
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

// create the player
    Player *player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    QPixmap playpic(":/images/player_ship1.png");
    QPixmap smallpic = playpic.scaled(QSize(50, 50));
    player->setPixmap(smallpic);
    player->setPos(gameScreenWidth / 2 - 50 / 2, gameScreenHeight - 50);
    scene->addItem(player);

//create view, only necessary for adding to a layout
    QGraphicsView * view = new QGraphicsView();
    view->setFixedSize(gameScreenWidth, gameScreenHeight);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);

//creating score
    score = new Score();
    score->setPos((gameScreenWidth / 2)  / 3, 0);
    scene->addItem(score);

//creating health
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

//spawning enemies and barriers
    spawnEnemy();
    spawnBarrier();

// spawn enemy lasers
    QTimer * timer_Enemy_lasers = new QTimer();
    QObject::connect(timer_Enemy_lasers, SIGNAL(timeout()), this, SLOT(spawn_enemy_laser()));
    timer_Enemy_lasers->start(1000);
    spawn_enemy_laser();
    spawn_enemy_laser();
    spawn_enemy_laser();
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
    show();
    setWindowState(Qt::WindowMaximized);
    showFullScreen();



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

