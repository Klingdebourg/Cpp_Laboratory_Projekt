#include "level2.h"

Level2::Level2()
{
//create the scene
scene = new QGraphicsScene();

setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(WINDOW_W,WINDOW_H);
scene->setSceneRect(0,0,WINDOW_W,WINDOW_H);

//Create the objects for the levels
Balken* balken1 = new Balken(600,1000,0,300);
Balken* balken2 = new Balken(300,400,0,300);
Balken* balken3 = new Balken(1000,600,0,300);
//Virus* virus = new Virus(1000,1000);
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT);
counter* counter1 = new counter;
counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
//Foehn* foehn = new foehn;
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
scene->addItem(balken1);
scene->addItem(balken2);
scene->addItem(balken3);
//scene->addItem(virus);
scene->addItem(feder);
scene->addItem(counter1);
//scene->addItem(foehn);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);


//+++++++++++Box2D ++++++++++++++++++++++++++++++++++++++

b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);                                   //Welt Definition

b2BodyDef groundBodyDef;
groundBodyDef.position.Set(0.0f, -600.0f);
b2Body* groundBody = world.CreateBody(&groundBodyDef);
b2PolygonShape groundBox;                                 //Weltbegrenzung
groundBox.SetAsBox(800.0f, 600.0f);
groundBody->CreateFixture(&groundBox, 0.0f);              //Welt jetzt erstellt


timeStep = 1.0f / 60.0f;
velocityIterations = 6;
positionIterations = 2;

b2Body* BodyBalken1 = world.CreateBody(&(balken1->bodyDefBalken));
BodyBalken1->CreateFixture(&fixtureDef);//FixtureDef auf Richtigkeit kontrollieren, Name könnte ein anderer sein in Balken + ggf Balken:fixture... verwenden




}
