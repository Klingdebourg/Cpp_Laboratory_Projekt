#ifndef MASKE_H
#define MASKE_H

#include <QGraphicsRectItem>
#include <QPainter>

#include "definitions.h"

class Maske : public QGraphicsRectItem {
public:
    Maske(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MASKE_H
