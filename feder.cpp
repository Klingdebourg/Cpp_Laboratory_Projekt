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
    //creates rectangle with given size at given location
    setRect(0, 0, FEDER_WIDTH, FEDER_HEIGHT);
    //position needs to be specified seperately as otherwise it is set to (0,0) allthough it is at a different position (dont know why)
    setPos(x_,y_);
    //makes the object focussable thus enables it to be moved
    setFlag(QGraphicsItem::ItemIsFocusable);

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
    //moves the transformation point to the lower end of the rectangle
    setTransformOriginPoint(QPointF(FEDER_WIDTH/2, FEDER_HEIGHT));
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
        if (spannung != 5) {
            spannung += 1;
            //shortens the appearance of the rectangle by transforming it with a matrix
            //this matrix does only affect the y coordinate of the object, the last two values are for translation purposes (dx, dy)
            setTransform(QTransform(1, 0, 0, (1 - 0.1*spannung), 0, 0));
        }
        break;
    case Qt::Key_Up:
        spannung = 0;
        setTransform(QTransform(1,0,0,1,0,0));
    }
}
