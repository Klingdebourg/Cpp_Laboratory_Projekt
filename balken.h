#ifndef BALKEN_H
#define BALKEN_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>

#include <math.h>

#include "definitions.h"




class Balken : public QGraphicsRectItem {
public:
    enum balkenType {
        statisch,
        translatorisch,
        rotatorisch
    };

    enum modification {
        LEFT,
        RIGHT,
        NONE
    };

    Balken(int x, int y, int rotation, int length, balkenType typ);
    QRectF boundingRect() const;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPosition(QPointF point);
    void unmodified();
    void setRotation(qreal angle);

    int getRotation() const;
    int getLength() const;
    balkenType getType() const;
    modification wasModified() const;

private:
    QPointF position;
    int rotation;
    int length;
    balkenType type;
    //to show the level if the balken has been modified in order to update its box2d body
    modification modified;
};

#endif // BALKEN_H
