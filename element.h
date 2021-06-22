#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsItem>
#include <box2d.h>

struct Element {
    QGraphicsItem *item = nullptr;
    b2Body *body = nullptr;
    b2BodyDef *bodyDef = nullptr;
    b2FixtureDef *fixture = nullptr;


    ~Element() {
        if (bodyDef != nullptr) {
            delete bodyDef;
            bodyDef = nullptr;
        }
        if (fixture != nullptr) {
            delete fixture;
            fixture = nullptr;
        }
    }
};

#endif // ELEMENT_H
