#include "endscreen.h"
#include "Game.h"
#include "ui_endscreen.h"
#include "menu.h"
#include <QInputDialog>

extern Game * game;

EndScreen::EndScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndScreen)

{

    ui->setupUi(this);
    EndScreen::showFullScreen();
    ui->score1st->setText(QString::number(score1));
    ui->score2nd->setText(QString::number(score2));
    ui->score3rd->setText(QString::number(score3));
    ui->score4th->setText(QString::number(score4));

    ui->name1st->setText(name1);
    ui->name2nd->setText(name2);
    ui->name3rd->setText(name3);
    ui->name4th->setText(name4);

    checkscore();
}

void EndScreen::checkscore(){
    int pscore = game->score->getScore();
    int temp;
    QString tmpname;
    if (pscore>score4){
        QString pname= QInputDialog::getText(0,"New High Score!!!!","PLEASE ENTER YOUR NAME TO SAVE SCORE:");
        score4=pscore;
        name4=pname;
    }
    if (score4>score3){
        temp=score3;
        score3=score4;
        score4=temp;

        tmpname=name3;
        name3=name4;
        name4=tmpname;

    }
    if (score3>score2){
        temp=score2;
        score2=score3;
        score3=temp;

        tmpname=name2;
        name2=name3;
        name3=tmpname;
    }
    if (score2>score1){
        temp=score1;
        score1=score2;
        score2=temp;

        tmpname=name1;
        name1=name2;
        name2=tmpname;
    }
    ui->score1st->setText(QString::number(score1));
    ui->score2nd->setText(QString::number(score2));
    ui->score3rd->setText(QString::number(score3));
    ui->score4th->setText(QString::number(score4));

    ui->name1st->setText(name1);
    ui->name2nd->setText(name2);
    ui->name3rd->setText(name3);
    ui->name4th->setText(name4);
}

EndScreen::~EndScreen()
{
    delete ui;
}

void EndScreen::on_ExitGame_clicked()
{
    close();
}


void EndScreen::on_StartGame_clicked()
{
    Menu *menu = new Menu();
    menu->show();
    hide();
}

