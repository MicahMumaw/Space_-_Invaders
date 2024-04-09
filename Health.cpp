#include "Health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //define score of 3
    health = 3;

    //Draw the text for health
    setPlainText(QString("Health: ") + QString::number(health)); //health 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); //health update
}

int Health::getHealth()
{
    return health;
}
