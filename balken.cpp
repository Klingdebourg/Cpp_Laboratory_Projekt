#include "balken.h"
#include "definitions.h"

/**
 * @brief creates a Balken at a certain position
 * @param x horizontal location of Balken
 * @param y vertical location of Balken
 * @param rotation initial rotation of Balken
 * @param length length of the balken
 * @param typ indicates whether the balken cannot be moved at all, can be translated or rotated with arrow keys
 */
Balken::Balken(int x, int y, int rotation, int length, balkenType typ) {

    //creates rectangle with given size at origin in scene coordinates
    this->length = length;
    setRect(-length/2, -BALKEN_WIDTH/2, length, BALKEN_WIDTH);
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
    setRotation(getRotation());

    if (typ != statisch) {
        //makes the object focussable thus enables it to be moved
        setFlag(QGraphicsItem::ItemIsFocusable);
        //makes the item selectable
        setFlag(QGraphicsItem::ItemIsSelectable);
    }

    //set the type of the balken
    type = typ;
}

/**
 * @brief Balken::boundingRect
 * @return the are to be redrawn when the item is updated
 */
QRectF Balken::boundingRect() const {
    return QRectF(0, 0, getLength(), BALKEN_WIDTH);
}

/**
 * @brief to move the Balken if it is in focus
 * @param event contains the pressed key
 */
void Balken::keyPressEvent(QKeyEvent *event) {
    //move the Balken
    switch(event->key()) {
    case Qt::Key_Left:
        //differentiate the movement depending on the type of the balken
        switch(type) {
        case translatorisch:
            position.setX(position.x() - 15 * cos(getRotation() * M_PI/180));
            position.setY(position.y() - 15 * sin(getRotation() * M_PI/180));
            setPos(position);
            break;
        case rotatorisch:
            rotation -= 5;
            setRotation(rotation);
            break;
        default:
            break;
        }
        break;
    case Qt::Key_Right:
        //differentiate the movement depending on the type of the balken
        switch(type) {
        case translatorisch:
            position.setX(position.x() + 15 * cos(getRotation() * M_PI/180));
            position.setY(position.y() + 15 * sin(getRotation() * M_PI/180));
            setPos(position);
            break;
        case rotatorisch:
            rotation += 5;
            setRotation(rotation);
            break;
        default:
            break;
        }
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

void Balken::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen = QPen();
    pen.setWidth(5);
    switch (this->type) {
    case statisch:
        pen.setColor(Qt::black);
        break;
    case translatorisch:
        pen.setColor(Qt::blue);
        break;
    case rotatorisch:
        pen.setColor(Qt::red);
        break;
    }
    painter->setPen(pen);
    painter->drawRect(0, 0, getLength(), BALKEN_WIDTH);
}

/**
 * @brief Balken::rot
 * @return current rotation of the Balken
 */
int Balken::getRotation() const{
    return rotation;
}

/**
 * @brief Balken::getLength
 * @return length of the Balken
 */
int Balken::getLength() const
{
    return length;
}

