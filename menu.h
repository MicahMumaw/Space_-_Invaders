#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QDebug>
#include <QScreen>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QButtonGroup>

#include <QKeyEvent> // to get keys to work

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();



private:
    Ui::Menu *ui;


protected:
    virtual void keyPressEvent(QKeyEvent *event); // recognizes the keys being pressed on keyboard

    //void mousePressEvent(QMouseEvent *event);
private slots:
    void on_ExitGame_clicked();
    void on_StartGame_clicked();

    void on_Instructions_clicked();

    void on_Settings_clicked();

    void on_HighScore_clicked();

public slots:
    void shoot();
    //void shipmove();
};

#endif // MENU_H
