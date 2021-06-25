#include "level2.h"


Level2::Level2(Game* game):Level(game, 2) {

    //wofür ist dies? (@johanna)
    x_last=ball->item->x();
    y_last=ball->item->y();

    //Create the objects specific for the level
    balken1 = new Element(BALKEN_S);
    dynamic_cast<Balken*>(balken1->item)->setPosition(QPointF(WINDOW_W*3.0f/8, WINDOW_H*5.0f/6));
    balken1->body = world->CreateBody(balken1->bodyDef);
    balken1->body->CreateFixture(balken1->fixture);
    balken1->body->SetTransform(b2Vec2(balken1->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f , WINDOW_H - balken1->item->y()+5), 0);
    levelscene->addItem(balken1->item);

    balken2 = new Element(BALKEN_R);
    dynamic_cast<Balken*>(balken2->item)->setPosition(QPointF(WINDOW_W*3.0f/16, WINDOW_H*1.0f/3));
    balken2->body = world->CreateBody(balken2->bodyDef);
    balken2->body->CreateFixture(balken2->fixture);
    balken2->body->SetTransform(b2Vec2(balken2->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken2->item->y()+5), 0);
    levelscene->addItem(balken2->item);

    balken3 = new Element(BALKEN_T);
    dynamic_cast<Balken*>(balken3->item)->setPosition(QPointF(WINDOW_W*5.0f/8, WINDOW_H/2.0f));
    balken3->body = world->CreateBody(balken3->bodyDef);
    balken3->body->CreateFixture(balken3->fixture);
    balken3->body->SetTransform(b2Vec2(balken3->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken3->item->y()+5), 0);
    levelscene->addItem(balken3->item);

    foehn = new Element(FOEHN);
    foehn->item->setPos(balken2->item->x()-100, balken2->item->y()-100);
    foehn->body = world->CreateBody(foehn->bodyDef);
    foehn->body->CreateFixture(foehn->fixture);
    foehn->body->SetTransform(b2Vec2(foehn->item->x()-25 + FOEHN_WIDTH/2.0f , WINDOW_H - foehn->item->y()+5), foehn->item->rotation());
    levelscene->addItem(foehn->item);

    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT+5);
    dynamic_cast<Feder*>(feder->item)->attachBall(* ball);



    //Maskenposition und Virus position setzen
    virus->item->setPos(balken3->item->x()+dynamic_cast<Balken*>(balken3->item)->getLength(),balken3->item->y()-150);
    maske1->item->setPos(balken3->item->x()-250,balken3->item->y()-50);
    maske2->item->setPos(virus->item->x()-250,virus->item->y());
    maske3->item->setPos(balken2->item->x()+dynamic_cast<Balken*>(balken2->item)->getLength()/2-25,balken2->item->y()-100);

}

