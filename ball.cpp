#include "ball.h"
#include "maske.h"
#include "virus.h"
#include "level.h"
#include "definitions.h"



Ball::Ball() {
    //creates an ellipse with given size at origin in scene coordinates
    setRect(0, 0, BALL_DIAM, BALL_DIAM);
    //moves the transformation point to the middle of the circle
    setTransformOriginPoint(QPointF(BALL_DIAM/2, BALL_DIAM/2));


}

//für move Funktion

int Ball::collidingItem(Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus){
    if (collidesWithItem(maske1)==true){
        return 1;
    } else if (collidesWithItem(maske2)==true){
        return 2;
    } else if (collidesWithItem(maske3)==true){
        return 3;
    } else if (collidesWithItem(virus)==true){
        return 4;
    } else {
        return 5;
    }
}

QRectF Ball::boundingRect() const {
    return QRectF(0, 0, BALL_DIAM, BALL_DIAM);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen(Qt::black, 1);
    QBrush brush(Qt::green, Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(QRectF(0, 0, BALL_DIAM, BALL_DIAM));

}

//QList <QGraphicsItem *> Ball::collidingList(){
//    ///Liste mit kollidierenden Elementen erzeugen
//    QList <QGraphicsItem *> colliding_items = collidingItems();
//    return colliding_items;
//}
