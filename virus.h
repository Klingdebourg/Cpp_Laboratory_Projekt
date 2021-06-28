#ifndef VIRUS_H
#define VIRUS_H

#include "QGraphicsEllipseItem"
#include <QRectF>
#include <QPainter>

class Virus : public QGraphicsEllipseItem {
public:
    Virus(int x, int y, QRectF *a = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // VIRUS_H
