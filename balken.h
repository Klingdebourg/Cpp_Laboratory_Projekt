#ifndef BALKEN_H
#define BALKEN_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

#include <math.h>

#include <box2d/box2d.h>


#define WINDOW_W 1600
#define WINDOW_H 1200
#define BALKEN_WIDTH 20

class Balken : public QGraphicsRectItem {
public:
    Balken(int x, int y, int rotation, int length);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    int rot() const;
    b2BodyDef bodyDefBalken;

private:
    QPointF position;
    int rotation;
};

#endif // BALKEN_H
