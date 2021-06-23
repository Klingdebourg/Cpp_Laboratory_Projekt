#include "level2.h"


Level2::Level2(Game* game):Level(game, 2) {

    //Create the objects for the levels
    balken1 = new Element();
    balken1->item = new Balken(600,1000,0,300, rotatorisch);
    balken1->bodyDef = new b2BodyDef();
    balken1->bodyDef->type = b2_staticBody;
    balken1->body = world->CreateBody(balken1->bodyDef);
    balken1->shape = new b2PolygonShape();
    dynamic_cast<b2PolygonShape*>(balken1->shape)->SetAsBox(dynamic_cast<Balken*>(balken1->item)->getLength(), BALKEN_WIDTH);
    balken1->fixture = new b2FixtureDef();
    balken1->fixture->shape= balken1->shape;
    balken1->fixture->density=0.0f;
    balken1->body->CreateFixture(balken1->fixture);
    levelscene->addItem(balken1->item);

    balken2 = new Element();
    balken2->item = new Balken(300,400,0,300, statisch);
    balken2->bodyDef = new b2BodyDef();
    balken2->bodyDef->type = b2_staticBody;
    balken2->body = world->CreateBody(balken2->bodyDef);
    balken2->shape = new b2PolygonShape();
    dynamic_cast<b2PolygonShape*>(balken2->shape)->SetAsBox(dynamic_cast<Balken*>(balken2->item)->getLength(), BALKEN_WIDTH);
    balken2->fixture = new b2FixtureDef();
    balken2->fixture->shape= balken2->shape;
    balken2->fixture->density=0.0f;
    balken2->body->CreateFixture(balken2->fixture);
    levelscene->addItem(balken2->item);

    balken3 = new Element();
    balken3->item = new Balken(1000,600,0,300, statisch);             //translatorisch?
    balken3->bodyDef = new b2BodyDef();
    balken3->bodyDef->type = b2_staticBody;
    balken3->body = world->CreateBody(balken3->bodyDef);
    balken3->shape = new b2PolygonShape();
    dynamic_cast<b2PolygonShape*>(balken3->shape)->SetAsBox(dynamic_cast<Balken*>(balken3->item)->getLength(), BALKEN_WIDTH);
    balken3->fixture = new b2FixtureDef();
    balken3->fixture->shape= balken3->shape;
    balken3->fixture->density=0.0f;
    balken3->body->CreateFixture(balken3->fixture);
    levelscene->addItem(balken3->item);

    feder->item->setPos(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT);
    dynamic_cast<Feder*>(feder->item)->attachBall(* ball);

    x_last=ball->item->x();
    y_last=ball->item->y();


    //levelscene->addItem(foehn->item);
    //foehn = new Foehn(balken2->x()-100, balken2->y()-100);


    //Maskenposition und Virus position setzen
    virus->item->setPos(balken3->item->x()+dynamic_cast<Balken*>(balken3->item)->getLength(),balken3->item->y()-150);
    maske1->item->setPos(balken3->item->x()-250,balken3->item->y()-50);
    maske2->item->setPos(virus->item->x()-250,virus->item->y());
    maske3->item->setPos(balken2->item->x()+dynamic_cast<Balken*>(balken2->item)->getLength()/2-25,balken2->item->y()-100);

}

