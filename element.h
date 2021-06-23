#ifndef ELEMENT_H
#define ELEMENT_H
#include "definitions.h"
#include <QGraphicsItem>
#include "balken.h"
#include "ball.h"
#include "feder.h"
#include "foehn.h"
#include "maske.h"
#include "virus.h"
#include <box2d.h>

enum elementType {
    BALKEN,
    BALL,
    FEDER,
    FOEHN,
    MASKE,
    VIRUS
};


struct Element {
    QGraphicsItem *item = nullptr;
    b2Body *body = nullptr;
    b2BodyDef *bodyDef = nullptr;
    b2Shape *shape = nullptr;
    b2FixtureDef *fixture = nullptr;
    elementType typ;

    /**
     * @brief Element standard construktor
     */
    Element(){
    }
    /**
     * @brief Element specific constructor
     * still requires the definition of the body, linking of body and fixture and adding to the Qt-world
     * @param typ defines type of element
     */
    Element(elementType typ) {
        ///define item
        switch(typ) {
        case BALKEN:
            this->item = new Balken(0, 0, 0, BALKEN_LENGTH_DEFAULT, statisch);
            break;
        case BALL:
            this->item = new Ball();
            break;
        case FEDER:
            //this->item = new Feder(0, 0);
            //momentan muss eine Feder noch von hand nach dem konstruktor erstellt
            //werden um "zirkulaere" includes zu vermeiden
            break;
        case FOEHN:
            this->item = new Foehn(0, 0);
            break;
        case MASKE:
            this->item = new Maske(0, 0);
            break;
        case VIRUS:
            this->item = new Virus(0, 0);
            break;
        }
        ///define bodyDef
        this->bodyDef = new b2BodyDef();
        switch(typ) {
        case BALL:
            this->bodyDef->type = b2_dynamicBody;
            break;
        default:
            this->bodyDef->type = b2_staticBody;
            break;
        }
        ///define shape
        switch(typ) {
        case BALKEN:
        case FEDER:
        case FOEHN:
        case MASKE:
            this->shape = new b2PolygonShape();
            if (typ == BALKEN)
                dynamic_cast<b2PolygonShape*>(this->shape)->SetAsBox(BALKEN_LENGTH_DEFAULT, BALKEN_WIDTH);
            else if (typ == FEDER)
                dynamic_cast<b2PolygonShape*>(this->shape)->SetAsBox(FEDER_WIDTH, FEDER_HEIGHT);
            else if (typ == FOEHN)
                dynamic_cast<b2PolygonShape*>(this->shape)->SetAsBox(FOEHN_WIDTH, FOEHN_WIDTH);
            else
                dynamic_cast<b2PolygonShape*>(this->shape)->SetAsBox(MASKE_WIDTH, MASKE_WIDTH);
            break;
        case BALL:
        case VIRUS:
            this->shape = new b2CircleShape();
            if (typ == BALL)
                this->shape->m_radius = BALL_DIAM/2;
            else
                this->shape->m_radius = VIRUS_DIAM/2;
            break;
        }
        ///define fixture
        this->fixture = new b2FixtureDef();
        this->fixture->shape = this->shape;
        switch(typ) {
        case BALL:
            this->fixture->density = BALL_DENSITY;
            this->fixture->friction = BALL_FRICTION;
            this->fixture->restitution = BALL_RESTITUTION;
            break;
        default:
            this->fixture->density = 0.0f;
            this->fixture->friction = 0.0f;
            this->fixture->restitution = 0.0f;
            break;
        }
    }


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
