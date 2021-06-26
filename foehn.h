#ifndef FOEHN_H
#define FOEHN_H

#include <QGraphicsPolygonItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>

#include "definitions.h"


class Foehn : public QGraphicsPolygonItem{
public:
    Foehn(int x, int y, int alpha);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); 
    bool isOn() const;
private:
    QPolygon *triangle;
    bool foehn_on = false;
};

#endif // FOEHN_H
