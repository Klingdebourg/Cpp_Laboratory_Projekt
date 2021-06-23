#include "feder.h"
#include "definitions.h"

#include <QDebug>


/**
 * @brief Constructor creating a spring at a requested position with a fixed size
 * @param x requested x position
 * @param y requested y position
 */

Feder::Feder(int x, int y) {
    //creates rectangle with given size at origin in scene coordinates
    setRect(0, 0, FEDER_WIDTH, FEDER_HEIGHT);
    //moves the transformation point to the lower end of the rectangle
    setTransformOriginPoint(QPointF(FEDER_WIDTH/2, FEDER_HEIGHT));
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
    //moves the item to the given position in scene coordinates
    setPos(x_, y_);
    //makes the object focussable thus enables it to be moved
    setFlag(QGraphicsItem::ItemIsFocusable);
    //makes the item selectable
    setFlag(QGraphicsItem::ItemIsSelectable);

    //set initial tension to 0 (i.e. relaxed)
    spannung = 0;

    //indicate that there is no ball attached
    ball = nullptr;
    isBallAttached = false;
}

/**
 * @brief Constructor creating a spring at a requested position with a fixed size with a ball already attached to it
 * @param x requested x position
 * @param y requested y position
 * @param ball ball connected to the spring
 */
Feder::Feder(int x, int y, Element *ball) {
    //creates rectangle with given size at origin in scene coordinates
    setRect(0, 0, FEDER_WIDTH, FEDER_HEIGHT);
    //moves the transformation point to the lower end of the rectangle
    setTransformOriginPoint(QPointF(FEDER_WIDTH/2, FEDER_HEIGHT));
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
    //moves the item to the given position in scene coordinates
    setPos(x_, y_);
    //makes the object focussable thus enables it to be moved
    setFlag(QGraphicsItem::ItemIsFocusable);
    //makes the item selectable
    setFlag(QGraphicsItem::ItemIsSelectable);

    //set initial tension to 0 (i.e. relaxed)
    spannung = 0;

    //attach the ball
    this->ball = ball;
    isBallAttached = true;
    this->ball->item->setPos(x_ + FEDER_WIDTH/2 - BALL_DIAM/2, y_ - BALL_DIAM);
    this->ball->body->SetTransform(b2Vec2(this->ball->item->x(), (WINDOW_H - this->ball->item->y())), this->ball->item->rotation());
}

/**
 * @brief Feder::boundingRect
 * @return the are to be redrawn when the item is updated
 */
QRectF Feder::boundingRect() const {
    return QRectF(0, 0, FEDER_WIDTH, FEDER_HEIGHT);
}

/**
 * @brief rotates, tensions or releaves the spring if it is in focus
 * @param event contains the pressed key
 */

void Feder::keyPressEvent(QKeyEvent *event)
{
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
        b2Vec2 ballStep = ball->body->GetPosition();
        qDebug() << ballStep.x << " " << ballStep.y;
        ball->body->ApplyLinearImpulseToCenter(b2Vec2(spannung*10000 * -sin(this->rotation() * M_PI/180), spannung*10000 * cos(this->rotation() * M_PI/180)), true);
        ballStep = ball->body->GetPosition();
        qDebug() << ballStep.x << " " << ballStep.y;
        isBallAttached = false;
        this->ball = nullptr;
    }

    //update shape of feder (change rotation and length)
    update();
    //update position of ball if it is attached
    if (this->isBallAttached)
        updateBall(* this->ball);

}

/**
 * @brief enables the object to be modified with keyboard input
 * @param event
 */
void Feder::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    switch(event->button()) {
    case Qt::LeftButton:
        setFocus();
    default:
        break;
    }
}

void Feder::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPen pen(Qt::black, 1);
    QBrush brush(Qt::black, Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(QRectF(0, 0.1*spannung*FEDER_HEIGHT, FEDER_WIDTH, FEDER_HEIGHT*(1-0.1*spannung)));
}

/**
 * @brief if a ball is connected to the feder, its position is updated (is used after the feder changes its position/tesnion)
 * @param ball to be changed
 */
void Feder::updateBall(Element &ball) {
    int x_ = x() + FEDER_WIDTH/2 - BALL_DIAM/2 + (FEDER_HEIGHT*(1-0.1*spannung) + BALL_DIAM/2) * sin(rotation() * M_PI/180);
    int y_ = y() + FEDER_HEIGHT  - BALL_DIAM/2 - (FEDER_HEIGHT*(1-0.1*spannung) + BALL_DIAM/2) * cos(rotation() * M_PI/180);
    dynamic_cast<Ball&>(* ball.item).setPos(x_, y_);
    ball.body->SetTransform(b2Vec2(x_, (WINDOW_H - y_)), dynamic_cast<Ball&>(* ball.item).rotation());
}

void Feder::attachBall(Element &ball) {
    this->isBallAttached = true;
    this->ball = &ball;
    updateBall(ball);
}

bool Feder::getBallAttached() const
{
    return isBallAttached;
}
