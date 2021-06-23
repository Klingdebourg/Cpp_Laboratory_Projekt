#include "maske.h"

Maske::Maske(int x, int y) {
    //creates rectangle with given size at origin in scene coordinates
    setRect(0, 0, MASKE_WIDTH, MASKE_WIDTH);
    //moves the transformation point to the lower end of the rectangle
    setTransformOriginPoint(QPointF(MASKE_WIDTH/2, MASKE_WIDTH/2));

    //moves the item to the given position in scene coordinates
    setPos(x, y);
}

QRectF Maske::boundingRect() const {
    return QRectF(0, 0, MASKE_WIDTH, MASKE_WIDTH);
}

void Maske::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen = QPen();
    pen.setWidth(3);
    pen.setColor(Qt::yellow);
    painter->setPen(pen);
    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, MASKE_WIDTH, MASKE_WIDTH), 0, 0);
    painter->drawPath(path);

}
