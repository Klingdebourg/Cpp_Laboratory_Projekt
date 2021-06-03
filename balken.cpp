#include "balken.h"

/**
 * @brief creates a Balken at a certain position
 * @param x horizontal location of Balken
 * @param y vertical location of Balken
 * @param rotation initial rotation of Balken
 * @param length length of the balken
 */
Balken::Balken(int x, int y, int rotation, int length) {

    //creates rectangle with given size at origin in scene coordinates
    setRect(0, 0, length, BALKEN_WIDTH);
    //moves the transformation point to the middle of the rectangle
    setTransformOriginPoint(QPointF(length/2, BALKEN_WIDTH/2));

    //moves the item to the given position in scene coordinates
    position.setX(x);
    position.setY(y);
    setPos(position);

    //rotates the item as requested
    if (rotation >= -90 && rotation < 90) {
        this->rotation = rotation;
    } else {
        rotation = (rotation + 90) % 360 - 90;
        if (rotation < 90)
            this->rotation = rotation;
        else
            this->rotation = rotation - 180;
    }
    setRotation(rot());

    //makes the object focussable thus enables it to be moved
    setFlag(QGraphicsItem::ItemIsFocusable);
    //makes the item selectable
    setFlag(QGraphicsItem::ItemIsSelectable);

}

/**
 * @brief to move the Balken if it is in focus
 * @param event contains the pressed key
 */
void Balken::keyPressEvent(QKeyEvent *event) {
    //move the Balken
    switch(event->key()) {
    case Qt::Key_Left:
        position.setX(position.x() - 15 * cos(rot() * M_PI/180));
        position.setY(position.y() - 15 * sin(rot() * M_PI/180));
        setPos(position);
        break;
    case Qt::Key_Right:
        position.setX(position.x() + 15 * cos(rot() * M_PI/180));
        position.setY(position.y() + 15 * sin(rot() * M_PI/180));
        setPos(position);
        break;
    }

}

/**
 * @brief enables the object to be modified with keyboard input
 * @param event
 */
void Balken::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch(event->button()) {
    case Qt::LeftButton:
        setFocus();
    default:
        break;
    }
}

int Balken::rot() const
{
    return rotation;
}
