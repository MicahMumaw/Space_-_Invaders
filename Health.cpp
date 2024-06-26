#include "Health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Harlow Solid Italic", 40));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::increase()
{
    if (health < 5)
    {
        health++;
        setPlainText(QString("Health: ") + QString::number(health));
    }
}

int Health::getHealth()
{
    return health;
}
