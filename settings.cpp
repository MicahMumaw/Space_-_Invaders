#include "settings.h"
#include "Game.h"
#include "ui_settings.h"
#include "menu.h"
#include <QtWidgets>


extern Game * game;

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    Settings::showFullScreen();
    QPixmap enpic(":/images/enemy1.png");
    enpic = enpic.scaled(QSize(75, 75));
    QIcon ButtonEn1(enpic);
    ui->pushButton_5->setIcon(ButtonEn1);
    ui->pushButton_5->setIconSize(enpic.rect().size());

    QPixmap enpic2(":/images/enemy2.png");
    enpic2 = enpic2.scaled(QSize(75, 75));
    QIcon ButtonEn2(enpic2);
    ui->pushButton_6->setIcon(ButtonEn2);
    ui->pushButton_6->setIconSize(enpic2.rect().size());

    QPixmap enpic3(":/images/enemy3.png");
    enpic3 = enpic3.scaled(QSize(75, 75));
    QIcon ButtonEn3(enpic3);
    ui->pushButton_7->setIcon(ButtonEn3);
    ui->pushButton_7->setIconSize(enpic3.rect().size());

    QPixmap playpic(":/images/player_ship1.png");
    playpic = playpic.scaled(QSize(75, 75));
    QIcon ButtonShip1(playpic);
    ui->pushButton_2->setIcon(ButtonShip1);
    ui->pushButton_2->setIconSize(playpic.rect().size());

    QPixmap playpic2(":/images/player_ship2.png");
    playpic2 = playpic2.scaled(QSize(75, 75));
    QIcon ButtonShip2(playpic2);
    ui->pushButton_3->setIcon(ButtonShip2);
    ui->pushButton_3->setIconSize(playpic2.rect().size());

    QPixmap playpic3(":/images/player_ship3.png");
    playpic3 = playpic3.scaled(QSize(75, 75));
    QIcon ButtonShip3(playpic3);
    ui->pushButton_4->setIcon(ButtonShip3);
    ui->pushButton_4->setIconSize(playpic3.rect().size());

    QPixmap laserpic(":/images/bullet.png");
    laserpic = laserpic.scaled(QSize(75, 75));
    QIcon LaserShip1(laserpic);
    ui->pushButton_9->setIcon(LaserShip1);
    ui->pushButton_9->setIconSize(laserpic.rect().size());

    QPixmap laserpic2(":/images/redbullet.png");
    laserpic2 = laserpic2.scaled(QSize(75, 75));
    QIcon LaserShip2(laserpic2);
    ui->pushButton_10->setIcon(LaserShip2);
    ui->pushButton_10->setIconSize(laserpic2.rect().size());

    QPixmap laserpic3(":/images/greenbullet.jpg");
    laserpic3 = laserpic3.scaled(QSize(75, 75));
    QIcon LaserShip3(laserpic3);
    ui->pushButton_11->setIcon(LaserShip3);
    ui->pushButton_11->setIconSize(laserpic3.rect().size());

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
    ui->pushButton_2->setStyleSheet("background-color: rgb(135,135,135);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_3_clicked()
{
    playeroption=2;
    ui->pushButton_2->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(135,135,135);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_4_clicked()
{
    playeroption=3;
    ui->pushButton_2->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_4->setStyleSheet("background-color: rgb(135,135,135);");
}


void Settings::on_pushButton_5_clicked()
{
    alienoption=1;
    ui->pushButton_5->setStyleSheet("background-color: rgb(135,135,135);");
    ui->pushButton_6->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_7->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_6_clicked()
{
    alienoption=2;
    ui->pushButton_5->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_6->setStyleSheet("background-color: rgb(135,135,135);");
    ui->pushButton_7->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_7_clicked()
{
    alienoption=3;
    ui->pushButton_5->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_6->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_7->setStyleSheet("background-color: rgb(135,135,135);");
}


void Settings::on_pushButton_9_clicked()
{
    laseroption=1;
    ui->pushButton_9->setStyleSheet("background-color: rgb(135,135,135);");
    ui->pushButton_10->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_11->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_10_clicked()
{
    laseroption=2;
    ui->pushButton_9->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_10->setStyleSheet("background-color: rgb(135,135,135);");
    ui->pushButton_11->setStyleSheet("background-color: rgb(0,0,0);");
}


void Settings::on_pushButton_11_clicked()
{
    laseroption=3;
    ui->pushButton_9->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_10->setStyleSheet("background-color: rgb(0,0,0);");
    ui->pushButton_11->setStyleSheet("background-color: rgb(135,135,135);");
}

