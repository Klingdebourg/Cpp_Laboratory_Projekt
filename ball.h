#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

#include <QGraphicsItem>
#include <QList>
#include "maske.h"
#include "virus.h"


class Ball : public QGraphicsEllipseItem {
public:
    Ball();
    //QList <QGraphicsItem *> collidingList();
    int collidingItem(Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus);
};

#endif // BALL_H
