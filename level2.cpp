#include "level2.h"


Level2::Level2(Game* game):Level(game, 2) {

    ballStep = b2Vec2(0,0);

    //wofür ist dies? (@johanna)
    x_last=ball->item->x();
    y_last=ball->item->y();

    //Create the objects specific for the level
    balken1 = new Element(BALKEN_S);
    dynamic_cast<Balken*>(balken1->item)->setPosition(QPointF(WINDOW_W*3.0f/10, WINDOW_H*5.0f/6));
    balken1->body = world->CreateBody(balken1->bodyDef);
    balken1->body->CreateFixture(balken1->fixture);
    balken1->body->SetTransform(b2Vec2(balken1->item->x(), WINDOW_H - balken1->item->y()), 0);
    levelscene->addItem(balken1->item);

    balken2 = new Element(BALKEN_T);
    dynamic_cast<Balken*>(balken2->item)->setPosition(QPointF(WINDOW_W*4.0f/10, WINDOW_H*5.0f/12));
    balken2->body = world->CreateBody(balken2->bodyDef);
    balken2->body->CreateFixture(balken2->fixture);
    balken2->body->SetTransform(b2Vec2(balken2->item->x(), WINDOW_H - balken2->item->y()), 0);
    levelscene->addItem(balken2->item);

    balken3 = new Element(BALKEN_R);
    dynamic_cast<Balken*>(balken3->item)->setPosition(QPointF(WINDOW_W/2.0f, WINDOW_H*1.0f/4.0f));
    balken3->body = world->CreateBody(balken3->bodyDef);
    balken3->body->CreateFixture(balken3->fixture);
    balken3->body->SetTransform(b2Vec2(balken3->item->x(), WINDOW_H - balken3->item->y()), 0);
    levelscene->addItem(balken3->item);

    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT);
    //dynamic_cast<Feder*>(feder->item)->attachBall(* ball);
    ball->item->setPos(balken2->item->x(), balken2->item->y()-FOEHN_WIDTH);
    ball->body->SetTransform(b2Vec2(ball->item->x(), (WINDOW_H - ball->item->y())), 0);
    ballStep.Set(ball->item->x(), ball->item->y());
    qDebug() << ballStep.x << " " << ballStep.y;
    ballStep = ball->body->GetPosition();
    qDebug() << ballStep.x << " " << ballStep.y;

    //Maskenposition und Virus position setzen
    virus->item->setPos(WINDOW_W*4.0f/5,balken3->item->y());
    maske1->item->setPos((balken1->item->x()+3*balken2->item->x())/4 + (BALKEN_LENGTH_DEFAULT-MASKE_WIDTH)/2, (balken1->item->y()+balken2->item->y())/2 - BALL_DIAM - MASKE_WIDTH);
    maske2->item->setPos((balken2->item->x()+balken3->item->x())/2 + (BALKEN_LENGTH_DEFAULT-MASKE_WIDTH)/2, (balken2->item->y()+balken3->item->y())/2);
    maske3->item->setPos((balken1->item->x()+BALKEN_LENGTH_DEFAULT+virus->item->x())/2, balken3->item->y());

}

