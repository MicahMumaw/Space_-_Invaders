#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QWidget>

namespace Ui {
class HighScores;
}

class HighScores : public QWidget
{
    Q_OBJECT

public:
    explicit HighScores(QWidget *parent = nullptr);
    ~HighScores();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HighScores *ui;
};

#endif // HIGHSCORES_H
