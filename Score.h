#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score: public QGraphicsTextItem{

public:
    Score(QGraphicsItem * parent = 0);
    void increase(int points);
    int getScore();
private:
    int score;
};

#endif // SCORE_H
