#include "level2.h"


Level2::Level2(Game* game):Level(game, 2) {

    ///Create the objects specific for level 2 and set the positions

    ballStep = b2Vec2(0,0);

    x_last=ball->item->x();
    y_last=ball->item->y();

    //Create the objects specific for the level

    balken.append(new Element(BALKEN_S));
    dynamic_cast<Balken*>(balken.at(0)->item)->setPosition(QPointF(WINDOW_W*8.0f/20, WINDOW_H*5.0f/6));
    balken.at(0)->body = world->CreateBody(balken.at(0)->bodyDef);
    balken.at(0)->body->CreateFixture(balken.at(0)->fixture);
    balken.at(0)->body->SetTransform(b2Vec2(balken.at(0)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken.at(0)->item->y()+5), 0);
    levelscene->addItem(balken.at(0)->item);

    balken.append(new Element(BALKEN_T));
    dynamic_cast<Balken*>(balken.at(1)->item)->setPosition(QPointF(WINDOW_W*9.0f/20, WINDOW_H/2));
    balken.at(1)->body = world->CreateBody(balken.at(1)->bodyDef);
    balken.at(1)->body->CreateFixture(balken.at(1)->fixture);
    balken.at(1)->body->SetTransform(b2Vec2(balken.at(1)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken.at(1)->item->y()+5), 0);
    levelscene->addItem(balken.at(1)->item);

    balken.append(new Element(BALKEN_R));
    dynamic_cast<Balken*>(balken.at(2)->item)->setPosition(QPointF(WINDOW_W*10.0f/20, WINDOW_H*3.0f/12));
    balken.at(2)->body = world->CreateBody(balken.at(2)->bodyDef);
    balken.at(2)->body->CreateFixture(balken.at(2)->fixture);
    balken.at(2)->body->SetTransform(b2Vec2(balken.at(2)->item->x()-25 + BALKEN_LENGTH_DEFAULT/2.0f, WINDOW_H - balken.at(2)->item->y()+5), 0);
    levelscene->addItem(balken.at(2)->item);

    //Feder positionieren und Ball verbinden
    feder->item->setPos(balken.at(0)->item->x()+(balken.at(0)->item->boundingRect().width() - FEDER_WIDTH)/2, balken.at(0)->item->y()-FEDER_HEIGHT);

    dynamic_cast<Feder*>(feder->item)->attachBall(* ball);
    ballStep.Set(ball->item->x(), ball->item->y());
    qDebug() << ballStep.x << " " << ballStep.y;
    ballStep = ball->body->GetPosition();
    qDebug() << ballStep.x << " " << ballStep.y;

    //Maskenposition und Virus position setzen
    virus->item->setPos(balken.at(1)->item->x() + 2*BALKEN_LENGTH_DEFAULT,                              balken.at(2)->item->y() + BALKEN_WIDTH);
    maske1->item->setPos(ball->item->x() + BALL_DIAM,                                                   ball->item->y() - FEDER_HEIGHT);
    maske2->item->setPos((balken.at(1)->item->x() + balken.at(2)->item->x() + BALKEN_LENGTH_DEFAULT)/2, (balken.at(1)->item->y() + balken.at(2)->item->y())/2);
    maske3->item->setPos(virus->item->x() - FEDER_HEIGHT,                                               virus->item->y() + VIRUS_DIAM/2 - MASKE_WIDTH/2);


}
