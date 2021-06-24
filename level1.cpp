#include "level1.h"



Level1::Level1(Game* game):Level(game,1) {

    //Create the objects specific for the level
    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(0)->item)->setPosition(QPointF(WINDOW_W/2.0f, WINDOW_H*3.0f/4));
    balken.at(0)->body = world->CreateBody(balken.at(0)->bodyDef);
    balken.at(0)->body->CreateFixture(balken.at(0)->fixture);
    balken.at(0)->body->SetTransform(b2Vec2(balken.at(0)->item->x(), WINDOW_H - balken.at(0)->item->y()), 0);
    levelscene->addItem(balken.at(0)->item);
    /*
    balken1->item = new Balken(800,900,0,300,rotatorisch);
    balken1->bodyDef = new b2BodyDef();
    balken1->bodyDef->type = b2_staticBody;
    balken1->body = world->CreateBody(balken1->bodyDef);
    balken1->shape = new b2PolygonShape();
    //dynamic_cast<b2PolygonShape*>(balken1->shape)->m_centroid.Set(0, 0);
    dynamic_cast<b2PolygonShape*>(balken1->shape)->SetAsBox(dynamic_cast<Balken*>(balken1->item)->getLength(), BALKEN_WIDTH);
    balken1->fixture = new b2FixtureDef();
    balken1->fixture->density = 0.0f;
    balken1->fixture->friction = 0.0f;
    balken1->fixture->restitution = 0.0f;
    balken1->fixture->shape = balken1->shape;
    balken1->body->CreateFixture(balken1->fixture);
    balken1->body->SetTransform(b2Vec2(balken1->item->x(), WINDOW_H - balken1->item->y()), 0);
    levelscene->addItem(balken1->item);
    */

    feder->item->setPos(balken.at(0)->item->x()+(balken.at(0)->item->boundingRect().width() - FEDER_WIDTH)/2, balken.at(0)->item->y()-FEDER_HEIGHT);
    dynamic_cast<Feder*>(feder->item)->attachBall(*ball);
    ball->body->SetTransform(b2Vec2(ball->item->x(), (WINDOW_H - ball->item->y())), ball->item->rotation());
    ballStep = ball->body->GetPosition();
    qDebug() << ballStep.x << " " << ballStep.y;

    x_last=ball->item->x();
    y_last=ball->item->y();


    //Position der Masken und des Virus festlegen
    virus->item->setPos(balken.at(0)->item->x()-600,balken.at(0)->item->y()-725);
    maske1->item->setPos(balken.at(0)->item->x(),balken.at(0)->item->y()-275);
    maske2->item->setPos(balken.at(0)->item->x()-175,balken.at(0)->item->y()-450);
    maske3->item->setPos(balken.at(0)->item->x()-350,balken.at(0)->item->y()-575);

}
