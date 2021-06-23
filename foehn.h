#ifndef FOEHN_H
#define FOEHN_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>

#include "definitions.h"


class Foehn : public QGraphicsRectItem{
public:
    Foehn(int x, int y, int alpha);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool isOn() const;

private:
    bool foehn_on = false;
};

#endif // FOEHN_H
