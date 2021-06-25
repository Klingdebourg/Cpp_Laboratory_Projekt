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

    foehn_on = false;

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
    QBrush brush = QBrush();
    if (foehn_on) {
        pen.setWidth(3);
        brush.setColor(Qt::gray);
    } else {
        pen.setWidth(1);
        brush.setColor(Qt::white);
    }
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(0, 0, FOEHN_WIDTH, FOEHN_WIDTH);

}

bool Foehn::isOn() const {
    return foehn_on;
}
