#include "Game.h"
#include "qapplication.h"


int res_x, res_y;
int gameScreenWidth, gameScreenHeight, headerWidth, headerHeight;
int barrierSpacing, barrierWidth, num_of_barriers = 4;
int enemy_width, enemy_height, enemy_spacing;
int laser_width, laser_height;
int barrier_total_width, barrier_total_height, barrier_spacing, barrier_side_length, barrier_width, barrier_height;
int player_width, player_height;
int playeroption=1, alienoption=1, laseroption=1;
int score1=5000,score2=3000, score3=2000, score4=0120;
QString name1="Cheka", name2="John",name3="Micah",name4="Khoa";


Game::Game(QWidget *parent)
{
//Getting screen resolution. This is the entire screen the program is being ran on, not like window size.
    QScreen *screen = QGuiApplication::primaryScreen();
    QSize full_resolution = screen->geometry().size();
    qDebug() << "Screen resolution:" << full_resolution;

//Screen Variables Definition
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
    barrier_total_width = (res_x * 100) / 1366;
    barrier_total_height = res_y * 50 / 768;
    barrier_width = barrier_total_width / 10;
    barrier_height = barrier_total_height / 5;

    barrier_spacing = (gameScreenWidth - barrier_total_width * num_of_barriers) / 5 ;
    barrier_side_length  = barrier_total_width  / 10;

//Player Variables
    player_width = (50 * gameScreenWidth / 1366), player_height = (50 * gameScreenHeight / 768);

//Enemy Variables
    enemy_width = (res_x * 50 / 1366), enemy_height = enemy_width;
    enemy_spacing = 25;

//Laser Variables
    laser_width = (res_x * 6 / 1366), laser_height = (res_y * 40 / 768);

//Header Label
    header_Label = new QLabel("Space Invaders",this);
    header_Label->setStyleSheet("background-color: rgb(0,0,0);font: italic 50pt \"Harlow Solid Italic\";color:rgb(255, 255, 255)");
    header_Label->setFixedSize(headerWidth, headerHeight);
    header_Label->setAlignment(Qt::AlignCenter);

// create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, gameScreenWidth, gameScreenHeight);
    setBackgroundBrush(QBrush(QImage(":/images/bullet2.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

// create the player
    Player *player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    if (playeroption==1){
        QPixmap playpic(":/images/player_ship1.png");
        playpic = playpic.scaled(QSize(player_width, player_height));
        player->setPixmap(playpic);
    }else if(playeroption ==2){
        QPixmap playpic(":/images/player_ship2.png");
        playpic = playpic.scaled(QSize(player_width, player_height));
        player->setPixmap(playpic);
    }
    else{
        QPixmap playpic(":/images/player_ship3.png");
        playpic = playpic.scaled(QSize(player_width, player_height));
        player->setPixmap(playpic);
    }
    player->setPos(gameScreenWidth / 2 - player_width / 2, gameScreenHeight - player_height);
    scene->addItem(player);

//create view, only necessary for adding to a layout
    QGraphicsView * view = new QGraphicsView();
    view->setFixedSize(gameScreenWidth, gameScreenHeight);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(QBrush(QImage(":/images/bullet2.png")));
    view->setScene(scene);

//creating score
    score = new Score();
    score->setPos((gameScreenWidth / 2)  / 3, 0);
    scene->addItem(score);

//creating health
    health = new Health();
    health->setPos(health->x(),health->y());
    scene->addItem(health);

//spawning enemies and barriers
    player->spawnEnemy();
    player->spawnBarrier();

//spawning ufo
//    QTimer * spawn_ufo_timer = new QTimer();
//    QObject::connect(spawn_ufo_timer, SIGNAL(timeout()), player, SLOT(spawn_ufo()));
//    spawn_ufo_timer->start(1000);

//spawn enemy lasers
    QTimer * timer_Enemy_lasers = new QTimer();
    QObject::connect(timer_Enemy_lasers, SIGNAL(timeout()), player, SLOT(spawn_enemy_laser()));
    timer_Enemy_lasers->start(1000);

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

    // play background music
//        QMediaPlayer * music = new QMediaPlayer();
//        music->setMedia(QUrl("qrc:/sounds/spaceinvaders1.mpeg"));
//        music->setVolume(150);
//        music->play();
//        qDebug() << music->errorString();

}
