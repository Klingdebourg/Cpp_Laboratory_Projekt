#ifndef FEDER_H
#define FEDER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "ball.h"

#include <math.h>

#define WINDOW_W 1600
#define WINDOW_H 1200
#define FEDER_WIDTH 20
#define FEDER_HEIGHT 100

class Feder : public QGraphicsRectItem {
public:
    Feder(int x, int y);
    Feder(int x, int y, Ball &ball);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void updateBall(Ball &ball);

private:
    int spannung;
    bool isBallAttached;
    Ball *ball;
};

#endif // FEDER_H
