#include "endscreen.h"
#include "Game.h"
#include "ui_endscreen.h"
#include "menu.h"

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

