#include "level3.h"


Level3::Level3(Game* game):Level(game,3) {

    ///Create the objects specific for level 3 and set the positions

    x_last=ball->item->x();
    y_last=ball->item->y();



    //Create the objects specific for the level
    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(0)->item)->setPosition(QPointF(WINDOW_W*11/32, WINDOW_H*5/6));
    balken.at(0)->body = world->CreateBody(balken.at(0)->bodyDef);
    balken.at(0)->body->CreateFixture(balken.at(0)->fixture);
    balken.at(0)->body->SetTransform(b2Vec2(balken.at(0)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken.at(0)->item->y()+5), 0);
    levelscene->addItem(balken.at(0)->item);

    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(1)->item)->setPosition(QPointF(WINDOW_W*11/32, WINDOW_H*1/2));
    balken.at(1)->body = world->CreateBody(balken.at(1)->bodyDef);
    balken.at(1)->body->CreateFixture(balken.at(1)->fixture);
    balken.at(1)->body->SetTransform(b2Vec2(balken.at(1)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken.at(1)->item->y()+5), 0);
    levelscene->addItem(balken.at(1)->item);

    balken.append(new Element(BALKEN_R));
    dynamic_cast<Balken*>(balken.at(2)->item)->setPosition(QPointF(balken.at(1)->item->x() - BALKEN_LENGTH_DEFAULT, balken.at(1)->item->y() - 50));
    balken.at(2)->body = world->CreateBody(balken.at(2)->bodyDef);
    balken.at(2)->body->CreateFixture(balken.at(2)->fixture);
    balken.at(2)->body->SetTransform(b2Vec2(balken.at(2)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken.at(2)->item->y()+5), 0);
    levelscene->addItem(balken.at(2)->item);

    foehne.append(new Element(FOEHN));
    foehne.at(0)->item->setPos(balken.at(0)->item->x() + BALKEN_LENGTH_DEFAULT + 100, balken.at(0)->item->y() - FOEHN_WIDTH);
    //foehne.at(0)->item->setPos(WINDOW_W/2, WINDOW_H/2);
    foehne.at(0)->body = world->CreateBody(foehne.at(0)->bodyDef);
    foehne.at(0)->body->CreateFixture(foehne.at(0)->fixture);
    foehne.at(0)->body->SetTransform(b2Vec2(foehne.at(0)->item->x()+10-FOEHN_WIDTH/4, WINDOW_H - foehne.at(0)->item->y()+5-FOEHN_WIDTH/2), -foehne.at(0)->item->rotation());
    levelscene->addItem(foehne.at(0)->item);

    foehne.append(new Element(FOEHN));
    foehne.at(1)->item->setPos(balken.at(1)->item->x() + 3*BALKEN_LENGTH_DEFAULT, balken.at(1)->item->y() - 2.5f*FOEHN_WIDTH);
    foehne.at(1)->item->setRotation(-90);
    foehne.at(1)->body = world->CreateBody(foehne.at(1)->bodyDef);
    foehne.at(1)->body->CreateFixture(foehne.at(1)->fixture);
    foehne.at(1)->body->SetTransform(b2Vec2(foehne.at(1)->item->x()+20-FOEHN_WIDTH/4, WINDOW_H - foehne.at(1)->item->y()-10-FOEHN_WIDTH), -foehne.at(1)->item->rotation() * M_PI/180);
    levelscene->addItem(foehne.at(1)->item);


    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken.at(0)->item->x()+(balken.at(0)->item->boundingRect().width() - FEDER_WIDTH)/2, balken.at(0)->item->y()-FEDER_HEIGHT);
    dynamic_cast<Feder*>(feder->item)->attachBall(* ball);


    //Maskenpositionen und Virus
    virus->item->setPos( balken.at(1)->item->x() + BALKEN_LENGTH_DEFAULT/2 - VIRUS_DIAM/2,  balken.at(1)->item->y() - 100);
    maske1->item->setPos(foehne.at(0)->item->x() + FOEHN_WIDTH/2 - MASKE_WIDTH/2,           foehne.at(0)->item->y() - 200);
    maske2->item->setPos(balken.at(1)->item->x() + 1.9f*BALKEN_LENGTH_DEFAULT,                 balken.at(1)->item->y() - 350);
    maske3->item->setPos(foehne.at(1)->item->x() - 1.5f*FOEHN_WIDTH,                           foehne.at(1)->item->y() + FOEHN_WIDTH - MASKE_WIDTH/2);

}
