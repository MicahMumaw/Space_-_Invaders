#ifndef LASERENEMY_H
#define LASERENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <vector>
#include <QMessageBox>
#include <QProcess>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <cmath>
#include <QPushButton>
#include <QDebug>
#include <QMediaPlayer>

class LaserEnemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    LaserEnemy(QGraphicsItem * parent = 0);
    QFile scores_file;
    QString username = "fran";
    std::vector<QString> names;
    std::vector<int> scores;
    QTextStream scores_stream;

public slots:
    void move();
    void scorecheck();
private:
    int pixels_per_move_enemy_laser;
    QMediaPlayer *hit_sound;
};
#endif // LASERENEMY_H
