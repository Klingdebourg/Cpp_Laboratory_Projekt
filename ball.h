#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include "feder.h"

class Ball : public QGraphicsEllipseItem {
public:
    Ball(int x, int y, int radius);
};

#endif // BALL_H
