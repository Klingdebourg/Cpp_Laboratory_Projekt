#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include "feder.h"

#include <box2d/box2d.h>

class Ball : public QGraphicsEllipseItem {
public:
    Ball(int x, int y, int radius, QGraphicsItem *parent = nullptr);

    /*
    b2BodyDef bodyDefBall;
    b2CircleShape circle;
    b2FixtureDef fixtureDefBall;
    */
};

#endif // BALL_H
