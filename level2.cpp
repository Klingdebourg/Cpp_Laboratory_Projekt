#include "level2.h"


Level2::Level2(Game* game):Level(game, 2) {

    ballStep = b2Vec2(0,0);

    //wofür ist dies? (@johanna)
    x_last=ball->item->x();
    y_last=ball->item->y();

    //Create the objects specific for the level
    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(0)->item)->setPosition(QPointF(WINDOW_W*3.0f/10, WINDOW_H*5.0f/6));
    balken.at(0)->body = world->CreateBody(balken.at(0)->bodyDef);
    balken.at(0)->body->CreateFixture(balken.at(0)->fixture);
    balken.at(0)->body->SetTransform(b2Vec2(balken.at(0)->item->x(), WINDOW_H - balken.at(0)->item->y()), 0);
    levelscene->addItem(balken.at(0)->item);

    balken.append(new Element(BALKEN_R));
    dynamic_cast<Balken*>(balken.at(1)->item)->setPosition(QPointF(WINDOW_W*4.0f/10, WINDOW_H*5.0f/12));
    balken.at(1)->body = world->CreateBody(balken.at(1)->bodyDef);
    balken.at(1)->body->CreateFixture(balken.at(1)->fixture);
    balken.at(1)->body->SetTransform(b2Vec2(balken.at(1)->item->x(), WINDOW_H - balken.at(1)->item->y()), 0);
    levelscene->addItem(balken.at(1)->item);

    balken.append(new Element(BALKEN_R));
    dynamic_cast<Balken*>(balken.at(2)->item)->setPosition(QPointF(WINDOW_W/2.0f, WINDOW_H*1.0f/4.0f));
    balken.at(2)->body = world->CreateBody(balken.at(2)->bodyDef);
    balken.at(2)->body->CreateFixture(balken.at(2)->fixture);
    balken.at(2)->body->SetTransform(b2Vec2(balken.at(2)->item->x(), WINDOW_H - balken.at(2)->item->y()), 0);
    levelscene->addItem(balken.at(2)->item);

    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken.at(0)->item->x()+(balken.at(0)->item->boundingRect().width() - FEDER_WIDTH)/2, balken.at(0)->item->y()-FEDER_HEIGHT);
    //dynamic_cast<Feder*>(feder->item)->attachBall(* ball);
    ball->item->setPos(balken.at(1)->item->x(), balken.at(1)->item->y()-FOEHN_WIDTH);
    ball->body->SetTransform(b2Vec2(ball->item->x(), (WINDOW_H - ball->item->y())), 0);
    ballStep.Set(ball->item->x(), ball->item->y());
    qDebug() << ballStep.x << " " << ballStep.y;
    ballStep = ball->body->GetPosition();
    qDebug() << ballStep.x << " " << ballStep.y;

    //Maskenposition und Virus position setzen
    virus->item->setPos(WINDOW_W*4.0f/5,balken.at(2)->item->y());
    maske1->item->setPos((balken.at(0)->item->x()+3*balken.at(1)->item->x())/4 + (BALKEN_LENGTH_DEFAULT-MASKE_WIDTH)/2, (balken.at(0)->item->y()+balken.at(1)->item->y())/2 - BALL_DIAM - MASKE_WIDTH);
    maske2->item->setPos((balken.at(1)->item->x()+balken.at(2)->item->x())/2 + (BALKEN_LENGTH_DEFAULT-MASKE_WIDTH)/2, (balken.at(1)->item->y()+balken.at(2)->item->y())/2);
    maske3->item->setPos((balken.at(0)->item->x()+virus->item->x())/2+BALKEN_LENGTH_DEFAULT, balken.at(2)->item->y());

}

