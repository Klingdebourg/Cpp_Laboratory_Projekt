#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

#include <QGraphicsItem>
#include <QList>
#include <QPainter>
#include "maske.h"
#include "virus.h"

class Ball : public QGraphicsEllipseItem {
public:
    /**
     * @brief Ball simple constructor
     */
    Ball();
    int collidingItem(Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus);
    /**
     * @brief boundingRect implements virtual function
     * @return the area which contains the ball if it needs to be (re-)drawn
     */
    QRectF boundingRect() const;
    /**
     * @brief paint implements virtual function to draw the ball according to certain requirements
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BALL_H
