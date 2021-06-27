#ifndef FEDER_H
#define FEDER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include "ball.h"
#include "element.h"

#include <math.h>


class Feder : public QGraphicsRectItem {
public:
    Feder(int x, int y);
    Feder(int x, int y, Element *ball);
    QRectF boundingRect() const;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void updateBall(Element &ball);
    void attachBall(Element &ball);
    bool getBallAttached() const;

private:
    int spannung;
    long long spannungBall; // Eingefuert um einen Impulsunterschied beim Abschiessen des Balls zu spuehren
    bool isBallAttached;
    Element *ball;
};

#endif // FEDER_H
