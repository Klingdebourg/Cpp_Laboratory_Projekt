#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    /// draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::magenta);
    setBrush(brush);

    /// draw the text
    text = new QGraphicsTextItem(name,this);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    ///emit the signal
    emit clicked();
}
QString Button::gettext(){
    ///give back the text
    return text->toPlainText();
}
