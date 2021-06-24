#include "level3.h"


Level3::Level3(Game* game):Level(game,3) {

    //wofür ist dies? (@johanna)
    x_last=ball->item->x();
    y_last=ball->item->y();


    //Create the objects specific for the level
    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(0)->item)->setPosition(QPointF(WINDOW_W*11/32, WINDOW_H*5/6));
    balken.at(0)->body = world->CreateBody(balken.at(0)->bodyDef);
    balken.at(0)->body->CreateFixture(balken.at(0)->fixture);
    balken.at(0)->body->SetTransform(b2Vec2(balken.at(0)->item->x(), WINDOW_H - balken.at(0)->item->y()), 0);
    levelscene->addItem(balken.at(0)->item);

    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(1)->item)->setPosition(QPointF(WINDOW_W*11/32, WINDOW_H*1/3));
    balken.at(1)->body = world->CreateBody(balken.at(1)->bodyDef);
    balken.at(1)->body->CreateFixture(balken.at(1)->fixture);
    balken.at(1)->body->SetTransform(b2Vec2(balken.at(1)->item->x(), WINDOW_H - balken.at(1)->item->y()), 0);
    levelscene->addItem(balken.at(1)->item);

    balken.append(new Element(BALKEN_T));
    dynamic_cast<Balken*>(balken.at(2)->item)->setPosition(QPointF(WINDOW_W*19/32, WINDOW_H*13/24));
    dynamic_cast<Balken*>(balken.at(2)->item)->setRotation(-45);
    balken.at(2)->body = world->CreateBody(balken.at(2)->bodyDef);
    balken.at(2)->body->CreateFixture(balken.at(2)->fixture);
    balken.at(2)->body->SetTransform(b2Vec2(balken.at(2)->item->x(), WINDOW_H - balken.at(2)->item->y()), 0);
    levelscene->addItem(balken.at(2)->item);

    foehne.append(new Element(FOEHN));
    foehne.at(0)->item->setPos(balken.at(2)->item->x()-75,balken.at(2)->item->y()+125);
    foehne.at(0)->body = world->CreateBody(foehne.at(0)->bodyDef);
    foehne.at(0)->body->CreateFixture(foehne.at(0)->fixture);
    foehne.at(0)->body->SetTransform(b2Vec2(foehne.at(0)->item->x(), foehne.at(0)->item->y()), foehne.at(0)->item->rotation());
    levelscene->addItem(foehne.at(0)->item);

    foehne.append(new Element(FOEHN));
    foehne.at(1)->item->setPos(balken.at(1)->item->x()+650, balken.at(2)->item->y()-BALKEN_LENGTH_DEFAULT);
    foehne.at(1)->body = world->CreateBody(foehne.at(1)->bodyDef);
    foehne.at(1)->body->CreateFixture(foehne.at(1)->fixture);
    foehne.at(1)->body->SetTransform(b2Vec2(foehne.at(1)->item->x(), foehne.at(1)->item->y()), foehne.at(1)->item->rotation());
    levelscene->addItem(foehne.at(1)->item);


    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken.at(0)->item->x()+(balken.at(0)->item->boundingRect().width() - FEDER_WIDTH)/2, balken.at(0)->item->y()-FEDER_HEIGHT);
    dynamic_cast<Feder*>(feder->item)->attachBall(* ball);



    //Maskenpositionen und Virus
    virus->item->setPos(balken.at(1)->item->x()+BALKEN_LENGTH_DEFAULT/2-50,balken.at(1)->item->y()-100);
    maske1->item->setPos(balken.at(0)->item->x()+BALKEN_LENGTH_DEFAULT-50,virus->item->y()+250);
    maske2->item->setPos(balken.at(2)->item->x()+BALKEN_LENGTH_DEFAULT/2,balken.at(2)->item->y()-150);
    maske3->item->setPos(balken.at(2)->item->x(), virus->item->y()-100);

}
