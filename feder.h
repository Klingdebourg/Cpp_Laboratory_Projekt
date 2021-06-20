#ifndef FEDER_H
#define FEDER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include "ball.h"

#include <math.h>


class Feder : public QGraphicsRectItem {
public:
    Feder(int x, int y);
    Feder(int x, int y, Ball &ball);
    QRectF boundingRect() const;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void updateBall(Ball &ball);

private:
    int spannung;
    bool isBallAttached;
    Ball *ball;
};

#endif // FEDER_H
