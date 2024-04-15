#include "endscreen.h"
#include "ui_endscreen.h"
#include "menu.h"

EndScreen::EndScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndScreen)
{
    ui->setupUi(this);
    EndScreen::showFullScreen();
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

