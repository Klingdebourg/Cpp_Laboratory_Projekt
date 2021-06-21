#ifndef ELEMENT_H
#define ELEMENT_H

#include <box2d.h>
#include <QGraphicsItem>
enum shape {
    ELLIPSE,
    RECT
};

struct Element {
    QGraphicsItem *item;
    shape type;
    b2BodyDef *bodyDef;
    b2Body *body;
    b2FixtureDef *fixtureDef;
};

#endif // ELEMENT_H
