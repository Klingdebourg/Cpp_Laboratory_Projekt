#include "level1.h"



Level1::Level1(Game* game):Level(game,1) {

    ///Create the objects specific for level 1 and set the positions
    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(0)->item)->setPosition(QPointF(WINDOW_W/2.0f, WINDOW_H*3.0f/4));
    balken.at(0)->body = world->CreateBody(balken.at(0)->bodyDef);
    balken.at(0)->body->CreateFixture(balken.at(0)->fixture);
    balken.at(0)->body->SetTransform(b2Vec2(balken.at(0)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f , WINDOW_H - balken.at(0)->item->y()+5), 0);
    levelscene->addItem(balken.at(0)->item);

    feder->item->setPos(balken.at(0)->item->x()+(BALKEN_LENGTH_DEFAULT - FEDER_WIDTH)/2, balken.at(0)->item->y()-FEDER_HEIGHT);
    dynamic_cast<Feder*>(feder->item)->attachBall(*ball);
    ball->body->SetTransform(b2Vec2(ball->item->x(), (WINDOW_H - ball->item->y())), ball->item->rotation());
    ballStep = ball->body->GetPosition();
    qDebug() << ballStep.x << " " << ballStep.y;

    x_last=ball->item->x();
    y_last=ball->item->y();


    //Position der Masken und des Virus festlegen
    virus->item->setPos(WINDOW_W*1/8,WINDOW_H*3/16);
    maske1->item->setPos(balken.at(0)->item->x(),balken.at(0)->item->y()-dynamic_cast<Balken*>(balken.at(0)->item)->getLength());
    maske2->item->setPos(balken.at(0)->item->x()-dynamic_cast<Balken*>(balken.at(0)->item)->getLength()*3/4,balken.at(0)->item->y()-dynamic_cast<Balken*>(balken.at(0)->item)->getLength()*3/2);
    maske3->item->setPos(virus->item->x()+dynamic_cast<Feder*>(feder->item)->boundingRect().height()*2,virus->item->y()+dynamic_cast<Virus*>(virus->item)->boundingRect().width()/2);


}
