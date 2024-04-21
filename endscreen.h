#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QWidget>

namespace Ui {
class EndScreen;
}

class EndScreen : public QWidget
{
    Q_OBJECT

public:
    explicit EndScreen(QWidget *parent = nullptr);
    ~EndScreen();
public slots:
    void checkscore();

private slots:
    void on_ExitGame_clicked();

    void on_StartGame_clicked();

private:
    Ui::EndScreen *ui;
};

#endif // ENDSCREEN_H
