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
    Menu::showFullScreen();
    QPixmap alien("C:/Users/Franc/Downloads/alien.png"); // my alien image
    ui->Alien->setPixmap(alien); // shows alien in middle
    QPixmap ship("C:/Users/Franc/Downloads/ship.png"); // my ship image
    ui->LeftShip->setPixmap(ship); // shows ship on each side
    ui->RightShip->setPixmap(ship);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(shoot()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(shipmove()));
    timer->start(100);
    //setMouseTracking(true);


}

//void Menu::mousePressEvent(QMouseEvent *event){
//    if(ui->RightBullet->geometry().y()<0){
//        ui->RightBullet->move(100,475); // resets the ship back to normal spot
//        ui->LeftBullet->move(1210,520);
//    }
//}

void Menu::keyPressEvent(QKeyEvent *event){ // will detect if keys are pressed
    this->setFocusPolicy(Qt::NoFocus); // allows for the arrow keys to be detected
        switch(event->key()){
            case Qt::Key_Escape:// allows player to escape
                close();
                break;
            case Qt::Key_Space:// allows player to shoot
                if(ui->RightBullet->geometry().y() <0){
                    ui->RightBullet->move(130,540); // resets the ship back to normal spot
                    ui->LeftBullet->move(1240,540);
                }
                break;
        }
}

//void Menu::shipmove(){
//    int Ay=ui->Alien->geometry().y();
//    int Ax=ui->Alien->geometry().x();
//    ui->Alien->move(Ax,Ay);
//}

void Menu::shoot(){
    int Ry=ui->RightBullet->geometry().y()-50;
    int Rx=ui->RightBullet->geometry().x();
    ui->RightBullet->move(Rx,Ry);

    int Ly=ui->LeftBullet->geometry().y()-50;
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


void Menu::on_StartGame_clicked()
{
    game = new Game();
    game->show();
    hide();
}

void Menu::on_Instructions_clicked()
{

    Instruct *instruct = new Instruct();
    instruct->show();
    hide();
}


void Menu::on_Settings_clicked()
{
    Settings *settings = new Settings();
    settings->show();
    hide();
}


void Menu::on_HighScore_clicked()
{
    HighScores *highscores = new HighScores();
    highscores->show();
    hide();
}

