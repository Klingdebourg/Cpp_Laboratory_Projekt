#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

#include <QGraphicsItem>
#include <QList>
#include <QPainter>
#include "maske.h"
#include "virus.h"

class Ball : public QGraphicsEllipseItem {
public:
    Ball();
    //QList <QGraphicsItem *> collidingList();
    int collidingItem(Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BALL_H
