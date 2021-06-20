#include "foehn.h"
#include <QDebug>
#include "definitions.h"

Foehn::Foehn(int x, int y){
    setRect(x, y, FOEHN_BREITE, FOEHN_BREITE);
}

void Foehn::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch(event->button()) {
    case Qt::LeftButton:
        setFocus();
        if (foehn_on == true){
            foehn_on = false;
            qDebug() << "Foehn ist aus";
        }else if (foehn_on == false){
            foehn_on = true;
            qDebug() << "Foehn ist an";
        }
    default:
        break;
    }
}
