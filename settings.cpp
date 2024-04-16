#include "settings.h"
#include "Game.h"
#include "ui_settings.h"
#include "menu.h"
#include <QtWidgets>



Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    Settings::showFullScreen();
    QPixmap enpic(":/images/enemy1.png");
    QPixmap enemy1 = enpic.scaled(QSize(75, 75));
    QIcon ButtonEn1(enemy1);
    ui->pushButton_5->setIcon(ButtonEn1);
    ui->pushButton_5->setIconSize(enemy1.rect().size());

    QPixmap playpic(":/images/player_ship1.png");
    QPixmap ship1 = playpic.scaled(QSize(75, 75));
    QIcon ButtonShip1(ship1);
    ui->pushButton_2->setIcon(ButtonShip1);
    ui->pushButton_2->setIconSize(ship1.rect().size());

    QPixmap playpic2(":/images/player_ship2.png");
    QPixmap ship2 = playpic2.scaled(QSize(75, 75));
    QIcon ButtonShip2(ship2);
    ui->pushButton_3->setIcon(ButtonShip2);
    ui->pushButton_3->setIconSize(ship2.rect().size());

    QPixmap playpic3(":/images/player_ship3.png");
    QPixmap ship3 = playpic3.scaled(QSize(75, 75));
    QIcon ButtonShip3(ship3);
    ui->pushButton_4->setIcon(ButtonShip3);
    ui->pushButton_4->setIconSize(ship3.rect().size());

}

Settings::~Settings()
{
    delete ui;
}

void Settings::keyPressEvent(QKeyEvent *event){ // will detect if keys are pressed
    this->setFocusPolicy(Qt::NoFocus); // allows for the arrow keys to be detected
        switch(event->key()){
            case Qt::Key_Escape:// allows player to escape
                close();
                break;
        }
}

void Settings::on_pushButton_clicked()
{
    hide();
    Menu *menu = new Menu();
    menu->show();
}


void Settings::on_pushButton_2_clicked()
{
    playeroption=1;
    ui->pushButton_2->setStyleSheet("background-color: rgb(255,255,255);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_3_clicked()
{
    playeroption=2;
    ui->pushButton_2->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(255,255,255);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_4_clicked()
{
    playeroption=3;
    ui->pushButton_2->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(255,255,255);");
}

