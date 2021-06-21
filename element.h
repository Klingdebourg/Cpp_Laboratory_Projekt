#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsItem>
#include <box2d.h>

struct Element {
    QGraphicsItem *item = nullptr;
    b2Body *body = nullptr;
    b2BodyDef *bodyDef = nullptr;
    b2FixtureDef *fixture = nullptr;
};

#endif // ELEMENT_H
