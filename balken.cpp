#include "balken.h"

Balken::Balken(int x, int y, int rotation, int length, balkenType typ) {

    //creates rectangle with given size at origin in scene coordinates
    this->length = length;
    setRect(0, 0, length, BALKEN_WIDTH);
    //moves the transformation point to the middle of the rectangle
    setTransformOriginPoint(QPointF(length/2, BALKEN_WIDTH/2));

    //moves the item to the given position in scene coordinates
    setPosition(QPointF(x, y));

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
    setRotation(rotation);

    if (typ != statisch) {
        //makes the object focussable thus enables it to be moved
        setFlag(QGraphicsItem::ItemIsFocusable);
        //makes the item selectable
        setFlag(QGraphicsItem::ItemIsSelectable);
    }

    //set the type of the balken
    type = typ;
    modified = NONE;
}

QRectF Balken::boundingRect() const {
    return QRectF(0, 0, getLength()+6, BALKEN_WIDTH+6);
}

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
        modified = LEFT;
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
        modified = RIGHT;
        break;
    }


}

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
    QColor *color;
    switch (this->type) {
    case statisch:
        color = new QColor(0, 0, 0, 250);
        break;
    case translatorisch:
        color = new QColor(0, 255, 0, 50);
        break;
    case rotatorisch:
        color = new QColor(0, 255, 255, 50);
        break;
    }
    pen.setColor(*color);
    painter->setPen(pen);
    painter->drawRect(0, 0, getLength(), BALKEN_WIDTH);
}


void Balken::setPosition(QPointF point) {
    position.setX(point.x());
    position.setY(point.y());
    setPos(position);

}

void Balken::unmodified() {
    modified = NONE;
}

void Balken::setRotation(qreal angle) {
    rotation = angle;
    QGraphicsItem::setRotation(angle);
}

int Balken::getRotation() const{
    return rotation;
}

int Balken::getLength() const
{
    return length;
}

Balken::balkenType Balken::getType() const {
    return type;
}

Balken::modification Balken::wasModified() const{
    return modified;
}

