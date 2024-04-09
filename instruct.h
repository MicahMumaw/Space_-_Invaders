#ifndef INSTRUCT_H
#define INSTRUCT_H

#include <QWidget>


#include <QKeyEvent> // to get keys to work

namespace Ui {
class Instruct;
}

class Instruct : public QWidget
{
    Q_OBJECT

public:
    explicit Instruct(QWidget *parent = nullptr);
    ~Instruct();

private:
    Ui::Instruct *ui;

protected:
    virtual void keyPressEvent(QKeyEvent *event); // recognizes the keys being pressed on keyboard
private slots:
    void on_pushButton_clicked();
};

#endif // INSTRUCT_H
