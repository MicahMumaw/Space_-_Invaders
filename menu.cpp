#include "menu.h"
#include "highscores.h"
#include "settings.h"
#include "instruct.h"
#include "ui_menu.h"
#include "Game.h"
#include <QtWidgets>

Game * game;

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    Menu::showFullScreen(); // makes the screen
    QPixmap alien(":/images/enemy1.png"); // sets the button to the enemy type
    alien = alien.scaled(QSize(450, 300));
    ui->Alien->setPixmap(alien); // shows alien in middle
    QPixmap ship(":/images/player_ship1.png"); // sets the button to the player type
    ship = ship.scaled(QSize(350, 220));
    ui->LeftShip->setPixmap(ship); // shows ship on each side
    ui->RightShip->setPixmap(ship);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(shoot()));
    timer->start(10);
}

void Menu::keyPressEvent(QKeyEvent *event){ // will detect if keys are pressed
    this->setFocusPolicy(Qt::NoFocus); // allows for the arrow keys to be detected
        switch(event->key()){
            case Qt::Key_Escape:// allows player to escape
                close();
                break;
            case Qt::Key_Space:// allows player to shoot
                if(ui->RightBullet->geometry().y() <0){
                    ui->RightBullet->move(222,800); // resets the ship back to normal spot
                    ui->LeftBullet->move(1682,800);
                }
                break;
        }
}

void Menu::shoot(){ // the lasers will travel across screen
    int Ry=ui->RightBullet->geometry().y()-10;
    int Rx=ui->RightBullet->geometry().x();
    ui->RightBullet->move(Rx,Ry);

    int Ly=ui->LeftBullet->geometry().y()-10;
    int Lx=ui->LeftBullet->geometry().x();
    ui->LeftBullet->move(Lx,Ly);
}


Menu::~Menu()
{
    delete ui;
}

void Menu::on_ExitGame_clicked()
{
    close();
}


void Menu::on_StartGame_clicked() // starts the game
{
    game = new Game();
    game->show();
    hide();
}

void Menu::on_Instructions_clicked() // opens the instructon
{

    Instruct *instruct = new Instruct();
    instruct->show();
    hide();
}


void Menu::on_Settings_clicked() // opens settings
{
    Settings *settings = new Settings();
    settings->show();
    hide();
}


void Menu::on_HighScore_clicked() // opens highscore
{
    HighScores *highscores = new HighScores();
    highscores->show();
    hide();
}

