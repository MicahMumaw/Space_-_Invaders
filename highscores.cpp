#include "highscores.h"
#include "ui_highscores.h"
#include "menu.h"

HighScores::HighScores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScores)
{
    ui->setupUi(this);
    HighScores::showFullScreen();
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

