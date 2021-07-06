#include "virus.h"
#include <QRectF>
#include "definitions.h"

Virus::Virus(int x, int y)
{
    setRect(x, y, VIRUS_DIAM, VIRUS_DIAM);
}

QRectF Virus::boundingRect() const {
    return QRectF(0, 0, VIRUS_DIAM, VIRUS_DIAM);
}

void Virus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen(Qt::gray, 1);
    QBrush brush(Qt::red, Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(QRectF(0, 0, VIRUS_DIAM, VIRUS_DIAM));
}
