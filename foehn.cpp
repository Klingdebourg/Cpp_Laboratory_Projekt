#include "foehn.h"

Foehn::Foehn(int x, int y, int alpha){
    //creates rectangle with given size at origin in scene coordinates
    setRect(0, 0, FOEHN_WIDTH, FOEHN_WIDTH);
    //moves the transformation point to the lower end of the rectangle
    setTransformOriginPoint(QPointF(FOEHN_WIDTH/2, FOEHN_WIDTH));

    //moves the item to the given position in scene coordinates
    setPos(x, y);
    //rotates the item for the given angle
    setRotation(alpha);

}

void Foehn::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch(event->button()) {
    case Qt::LeftButton:
        setFocus();
        if (foehn_on) {
            foehn_on = false;
            update();
            qDebug() << "Foehn ist aus";
        } else {
            foehn_on = true;
            update();
            qDebug() << "Foehn ist an";
        }
    default:
        break;
    }
}

QRectF Foehn::boundingRect() const {
    return QRectF(0, 0, FOEHN_WIDTH, FOEHN_WIDTH);
}

void Foehn::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen = QPen();
    if (foehn_on) {
        pen.setWidth(6);
        pen.setColor(Qt::gray);
    } else {
        pen.setWidth(1);
        pen.setColor(Qt::black);
    }
    painter->setPen(pen);
    painter->drawRect(0, 0, FOEHN_WIDTH, FOEHN_WIDTH);

}
