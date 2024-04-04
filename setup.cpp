#include "setup.h"
#include "ui_setup.h"

Setup::Setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setup)
{
    ui->setupUi(this);


//Getting screen resolution. This is the entire screen the program is being ran on, not like window size.
    QScreen *screen = QGuiApplication::primaryScreen();
    QSize full_resolution = screen->geometry().size();
    qDebug() << "Screen resolution:" << full_resolution;


//Variable Definition
    res_x = full_resolution.width(), res_y = full_resolution.height();
    //FOR NO REASON AT ALL THESE DOUBLES JUST DON'T WORK.
    //gameScreenRatio = 1.5;
    //headerRatio = 0.07;
    headerWidth = res_x, headerHeight = res_x * 0.07;
    gameScreenWidth = res_y * 1.5;
    gameScreenHeight = res_y - headerHeight;


//Header Label
    header_Label = new QLabel("This is the header!", this);
    header_Label->setStyleSheet("background-color: rgb(150,150,150);");
    header_Label->setFixedSize(headerWidth, headerHeight);





//create up scene
    scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, gameScreenWidth, gameScreenHeight);

//Item to put into the scene
    Player * player = new Player();
    player->setRect(0, 0, 100, 100);

//add item to the scene
    scene->addItem(player);

//Make Item Focusable to allow Q events
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView * view = new QGraphicsView(this) ;

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(gameScreenWidth, gameScreenHeight);
    scene->setSceneRect(0, 0, gameScreenWidth, gameScreenHeight);
    view->setScene(scene);
    view->show();

    player->setPos(view->width()/2 - player->rect().width() / 2, view->height() - player->rect().height());

    for (int i = 0; i < 11; i++)
    {
        player->spawn();
    }


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

Setup::~Setup()
{
    delete ui;
}
