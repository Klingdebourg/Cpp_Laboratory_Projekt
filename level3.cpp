#include "level3.h"


Level3::Level3(Game* game):Level(game,3) {

    //Create the objects specific for the level
    balken1 = new Element(BALKEN_S);
    dynamic_cast<Balken*>(balken1->item)->setPosition(QPointF(WINDOW_W*11/32, WINDOW_H*5/6));
    balken1->body = world->CreateBody(balken1->bodyDef);
    balken1->body->CreateFixture(balken1->fixture);
    balken1->body->SetTransform(b2Vec2(balken1->item->x(), WINDOW_H - balken1->item->y()), 0);
    levelscene->addItem(balken1->item);

    balken2 = new Element(BALKEN_S);
    dynamic_cast<Balken*>(balken2->item)->setPosition(QPointF(WINDOW_W*11/32, WINDOW_H*1/3));
    balken2->body = world->CreateBody(balken2->bodyDef);
    balken2->body->CreateFixture(balken2->fixture);
    balken2->body->SetTransform(b2Vec2(balken2->item->x(), WINDOW_H - balken2->item->y()), 0);
    levelscene->addItem(balken2->item);

    balken3 = new Element(BALKEN_T);
    dynamic_cast<Balken*>(balken3->item)->setPosition(QPointF(WINDOW_W*19/32, WINDOW_H*13/24));
    dynamic_cast<Balken*>(balken3->item)->setRotation(-45);
    balken3->body = world->CreateBody(balken3->bodyDef);
    balken3->body->CreateFixture(balken3->fixture);
    balken3->body->SetTransform(b2Vec2(balken3->item->x(), WINDOW_H - balken3->item->y()), 0);
    levelscene->addItem(balken3->item);

    foehn1 = new Element(FOEHN);
    foehn1->item->setPos(balken3->item->x()-75,balken3->item->y()+125);
    foehn1->body = world->CreateBody(foehn1->bodyDef);
    foehn1->body->CreateFixture(foehn1->fixture);
    foehn1->body->SetTransform(b2Vec2(foehn1->item->x(), foehn1->item->y()), foehn1->item->rotation());
    levelscene->addItem(foehn1->item);

    foehn2 = new Element(FOEHN);
    foehn2->item->setPos(balken2->item->x()+650, balken3->item->y()-BALKEN_LENGTH_DEFAULT);
    foehn2->body = world->CreateBody(foehn2->bodyDef);
    foehn2->body->CreateFixture(foehn2->fixture);
    foehn2->body->SetTransform(b2Vec2(foehn2->item->x(), foehn2->item->y()), foehn2->item->rotation());
    levelscene->addItem(foehn2->item);


    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT);
    dynamic_cast<Feder*>(feder->item)->attachBall(* ball);



    //Maskenpositionen und Virus
    virus->item->setPos(balken2->item->x()+BALKEN_LENGTH_DEFAULT/2-50,balken2->item->y()-100);
    maske1->item->setPos(balken1->item->x()+BALKEN_LENGTH_DEFAULT-50,virus->item->y()+250);
    maske2->item->setPos(balken3->item->x()+BALKEN_LENGTH_DEFAULT/2,balken3->item->y()-150);
    maske3->item->setPos(balken3->item->x(), virus->item->y()-100);

}
