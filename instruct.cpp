#include "instruct.h"
#include "ui_instruct.h"
#include "menu.h"

Instruct::Instruct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Instruct)
{
    ui->setupUi(this);
    Instruct::showFullScreen();
}

Instruct::~Instruct()
{
    delete ui;
}

void Instruct::keyPressEvent(QKeyEvent *event){ // will detect if keys are pressed
    this->setFocusPolicy(Qt::NoFocus); // allows for the arrow keys to be detected
        switch(event->key()){
            case Qt::Key_Escape:// allows player to escape
                close();
                break;
        }
}

void Instruct::on_pushButton_clicked()
{
    hide();
    Menu *menu = new Menu();
    menu->show();
}

