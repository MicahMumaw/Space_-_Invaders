#ifndef LASERENEMY_H
#define LASERENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QFile>
#include <QTextStream>

class LaserEnemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    LaserEnemy(QGraphicsItem * parent = 0);
    QFile scores_file;
    QString username;
    std::vector<QString> names;
    std::vector<int> scores;
    QTextStream scores_stream;
    int score_pos;
    int score_ctr;
public slots:
    void move();
    void scorecheck();
};
#endif // LASERENEMY_H
