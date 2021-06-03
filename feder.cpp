#include "feder.h"

#include <QDebug>


/**
 * @brief Constructor creating a spring at a requested position with a fixed size
 * @param x requested x position
 * @param y requested y position
 */

Feder::Feder(int x, int y) {
    //make sure that coordinates lay inside the frame
    int x_, y_;
    if (x < FEDER_WIDTH/2)
        x_ = FEDER_WIDTH/2;
    else if (x > WINDOW_W - FEDER_WIDTH / 2)
        x_ = WINDOW_W - FEDER_WIDTH/2;
    else {
        x_ = x;
    }
    if (y < FEDER_HEIGHT/2)
        y_ = FEDER_HEIGHT/2;
    else if (y > WINDOW_H - FEDER_HEIGHT/2)
        y_ = WINDOW_H - FEDER_HEIGHT/2;
    else {
        y_ = y;
    }
    //creates rectangle with given size at origin in scene coordinates
    setRect(0, 0, FEDER_WIDTH, FEDER_HEIGHT);
    //moves the item to the given position in scene coordinates
    setPos(x_, y_);
    //moves the transformation point to the lower end of the rectangle
    setTransformOriginPoint(QPointF(FEDER_WIDTH/2, FEDER_HEIGHT));
    //makes the object focussable thus enables it to be moved
    setFlag(QGraphicsItem::ItemIsFocusable);
    //makes the item selectable
    setFlag(QGraphicsItem::ItemIsSelectable);

    //set initial tension to 0 (i.e. relaxed)
    spannung = 0;
}

/**
 * @brief rotates, tensions or releaves the spring after pressing the respective keys
 * @param event contains the pressed key
 */

void Feder::keyPressEvent(QKeyEvent *event)
{
    //sets the object into focus such that the scene can modify it
    setFocus();
    //modify the spring
    switch(event->key()) {
    case Qt::Key_Left:
        if (rotation() > -90)
            setRotation(rotation() - 3);
        break;
    case Qt::Key_Right:
        if (rotation() < 90)
            setRotation(rotation() + 3);
        break;
    case Qt::Key_Down:
        //defines a maximal tension for the spring (half of its length)
        if (spannung < 5)
            spannung += 1;
        break;
    case Qt::Key_Up:
        if (spannung > 0)
            spannung -= 1;
        break;
    case Qt::Key_Space:
        spannung = 0;
    }
    //update size of Feder, unfortunately also changes width
    //alternative could use "update" method but this would require a redraw of the Feder which can only be done from the scene
    setScale(1 - 0.1*spannung);

    /*
    //alternative to only scale device in height with a transformation matrix but didnt work as expected
    //shortens the appearance of the rectangle by transforming it with a matrix
    //this matrix does only affect the y coordinate of the object, the last two values are for translation purposes (dx, dy)
    qreal xx = pow(cos(rotation()), 2) + (1 - 0.1*spannung) * pow(sin(rotation()), 2);
    qreal yy = pow(sin(rotation()), 2) + (1 - 0.1*spannung) * pow(cos(rotation()), 2);
    qreal xy = sin(rotation()) * cos(rotation()) * 0.1 * spannung;
    setTransform(QTransform(xx, xy, xy, yy, 0, 0));
    */
}
