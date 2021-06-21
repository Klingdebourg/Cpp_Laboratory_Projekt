#include "level2.h"



Game* game2;

Level2::Level2(Game* game) : Level(game, 2) {

//Create the objects for the levels
balken1->item = new Balken(600,1000,0,300, statisch);
balken2->item= new Balken(300,400,0,300, rotatorisch);
balken3->item = new Balken(1000,600,0,300, translatorisch);
feder->item = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT, *ball);
//foehn->item = new Foehn(balken2->x()-100, balken2->y()-100);

//Create the objects for the levels
balken1->item = new Balken(600,1000,0,300, rotatorisch);
balken2->item = new Balken(300,400,0,300, statisch);
balken3->item = new Balken(1000,600,0,300, statisch);             //translatorisch?
feder->item = new Feder(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT, ball->item);
//foehn->item = new Foehn(balken2->item->x()-100, balken2->item->y()-100);

//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1->item);
levelscene->addItem(balken2->item);
levelscene->addItem(balken3->item);
levelscene->addItem(feder->item);
//levelscene->addItem(foehn);


//Maskenposition und Virus position setzen
virus->item->setPos(balken3->item->x()+balken3->item->getLength(),balken3->item->y()-150);
maske1->item->setPos(balken3->item->x()-250,balken3->item->y()-50);
maske2->item->setPos(virus->item->x()-250,virus->item->y());
maske3->item->setPos(balken2->item->x()+balken2->item->getLength()/2-25,balken2->item->y()-100);


//Unterer balken
b2BodyDef groundBodyDefBottom;
groundBodyDefBottom.type= b2_staticBody;
groundBodyDefBottom.position.Set(800,-1205);
b2Body* groundBodyBotton = world->CreateBody(&groundBodyDefBottom);
b2PolygonShape groundBoxBotton;
groundBoxBotton.SetAsBox(800.0f, 5.0f);
b2FixtureDef GroundBoxFixDefBotton;
GroundBoxFixDefBotton.shape= &groundBoxBotton;
GroundBoxFixDefBotton.density=0.0f;
groundBodyBotton->CreateFixture(&GroundBoxFixDefBotton);

//ball



float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 10;
int32 positionIterations = 8;

for (int32 i = 0; i < 600; ++i) {
    world->Step(timeStep, velocityIterations, positionIterations);

    b2Vec2 positionBall = ball->body->GetPosition();
    ball->item->setPos(positionBall.x, -positionBall.y );
    float angle = ball->body->GetAngle();
    qDebug() << positionBall.x<<" "<< positionBall.y<<" "<< angle;

    b2Vec2 positionBalken = groundBodyBotton->GetPosition();
    float angleBalken = groundBodyBotton->GetAngle();
    qDebug() << positionBalken.x<<" "<< positionBalken.y<<" "<< angleBalken;
}
}
