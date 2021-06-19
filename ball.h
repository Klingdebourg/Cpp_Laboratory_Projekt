#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

#define BALL_DIAM 70

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include "feder.h"

class Ball : public QGraphicsEllipseItem {
public:
    Ball();
    void move();
};

#endif // BALL_H
