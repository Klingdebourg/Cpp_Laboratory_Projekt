#ifndef FEDER_H
#define FEDER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include "ball.h"
#include "element.h"

#include <math.h>


class Feder : public QGraphicsRectItem {
public:
    Feder(int x, int y);
    Feder(int x, int y, Element *ball);
    /**
     * @brief boundingRect implements virtual function
     * @return the area which contains the feder if it needs to be (re-)drawn
     */
    QRectF boundingRect() const;
    /**
     * @brief rotates, tensions or releaves the spring if it is in focus
     * @param event contains the pressed key
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief enables the object to be modified with keyboard input
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief paint implements virtual function to draw the feder according to certain requirements
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    /**
     * @brief if a ball is connected to the feder, its position is updated (is used after the feder changes its position/tesnion)
     * @param ball to be changed
     */
    void updateBall(Element &ball);
    /**
     * @brief attachBall attaches a ball to the spring to move it accordingly when the feder is modifies
     * @param ball the ball to be modified
     */
    void attachBall(Element &ball);
    /**
     * @brief getBallAttached simple getter method
     * @return the ball which is currently attached
     */
    bool getBallAttached() const;

private:
    /**
     * @brief spannung the current state of tension of the feder
     */
    int spannung;
    /**
     * @brief spannungBall intorduced to regulate the impulse when shooting the ball
     */
    long long spannungBall;
    /**
     * @brief isBallAttached if a ball is currently attached to the feder
     */
    bool isBallAttached;
    /**
     * @brief ball the currently attached ball or a null pointer if no ball is attached
     */
    Element *ball;
};

#endif // FEDER_H
