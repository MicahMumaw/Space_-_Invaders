#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

#include <QKeyEvent> // to get keys to work

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;

protected:
    virtual void keyPressEvent(QKeyEvent *event); // recognizes the keys being pressed on keyboard
private slots:
    void on_pushButton_clicked();

};

#endif // SETTINGS_H
