#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QWidget>
#include <QKeyEvent> // to get keys to work

namespace Ui {
class Instruction;
}

class Instruction : public QWidget
{
    Q_OBJECT

public:
    explicit Instruction(QWidget *parent = nullptr);
    ~Instruction();

private:
    Ui::Instruction *ui;


protected:
    virtual void keyPressEvent(QKeyEvent *event); // recognizes the keys being pressed on keyboard
};

#endif // INSTRUCTION_H
