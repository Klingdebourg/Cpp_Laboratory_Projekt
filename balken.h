#ifndef BALKEN_H
#define BALKEN_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>

#include <math.h>


#define WINDOW_W 1600
#define WINDOW_H 1200
#define BALKEN_WIDTH 40

enum balkenType {
    statisch,
    translatorisch,
    rotatorisch
};

class Balken : public QGraphicsRectItem {
public:
    Balken(int x, int y, int rotation, int length, balkenType typ);
    QRectF boundingRect() const;
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getRotation() const;
    int getLength() const;

private:
    QPointF position;
    int rotation;
    int length;
    balkenType type;
};

#endif // BALKEN_H
