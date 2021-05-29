#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QDebug>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
    qDebug() << "Button clicked.";
}
