#include "highscores.h"
#include "ui_highscores.h"
#include "menu.h"
#include "Game.h"

HighScores::HighScores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScores)
{
    ui->setupUi(this);
    HighScores::showFullScreen();
    ui->score1st->setText(QString::number(score1));
    ui->score2nd->setText(QString::number(score2));
    ui->score3rd->setText(QString::number(score3));
    ui->score4th->setText(QString::number(score4));

    ui->name1st->setText(name1);
    ui->name2nd->setText(name2);
    ui->name3rd->setText(name3);
    ui->name4th->setText(name4);
}

HighScores::~HighScores()
{
    delete ui;
}

void HighScores::on_pushButton_clicked()
{
    hide();
    Menu *menu = new Menu();
    menu->show();
}

