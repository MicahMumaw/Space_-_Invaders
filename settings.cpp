#include "settings.h"
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
    QPixmap enemy1 = enpic.scaled(QSize(50, 50));
    QIcon ButtonEn1(enemy1);
    ui->pushButton_5->setIcon(ButtonEn1);
    ui->pushButton_5->setIconSize(enemy1.rect().size());

    QPixmap playpic(":/images/player_ship1.png");
    QPixmap ship1 = playpic.scaled(QSize(50, 50));
    QIcon ButtonShip1(ship1);
    ui->pushButton_2->setIcon(ButtonShip1);
    ui->pushButton_2->setIconSize(ship1.rect().size());

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

