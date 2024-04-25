#include "Score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //define score of 0
    score = 0;

    //Draw the text for score
    setPlainText(QString("Score: ") + QString::number(score)); //score 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Harlow Solid Italic", 40)); // makes score prettier
}

void Score::increase(int points)
{
    score+=points;
    setPlainText(QString("Score: ") + QString::number(score)); //score updates
}

int Score::getScore()
{
    return score;
}
