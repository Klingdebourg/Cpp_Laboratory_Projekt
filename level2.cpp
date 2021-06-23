#include "level2.h"
#include<QDebug>
#include<iostream>
#include <math.h>

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

//+++++Ball erstellen+++++++++++++
int xBall= 800; int yBall=-1000; int radius=50;
Ball *Ball1 = new Ball(800, 1000, 50);
//+++++++++++++++++



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

//++++++Ball adden+++++++++++++++
scene-> addItem(Ball1);
//+++++++++++++++++++++++++++++++


//+++++++++++Box2D ++++++++++++++++++++++++++++++++++++++

b2Vec2 gravity(0.0f, -10.0f);
b2World *world= new b2World(gravity);                        //Welt Definition

b2BodyDef groundBodyDefTop;                                  //BodyDefinitions
b2BodyDef groundBodyDefBotton;
b2BodyDef groundBodyDefLeft;
b2BodyDef groundBodyDefRight;
        

groundBodyDefTop.type= b2_staticBody;
groundBodyDefTop.position.Set(800,5);
b2Body* groundBodyTop = world->CreateBody(&groundBodyDefTop);
b2PolygonShape groundBoxTop;
groundBoxTop.SetAsBox(800.0f, 5.0f);
b2FixtureDef GroundBoxFixDefTop;
GroundBoxFixDefTop.shape= &groundBoxTop;
groundBodyTop->CreateFixture(&GroundBoxFixDefTop);

groundBodyDefBotton.type= b2_staticBody;
groundBodyDefBotton.position.Set(800,-1205);
b2Body* groundBodyBotton = world->CreateBody(&groundBodyDefBotton);
b2PolygonShape groundBoxBotton;
groundBoxBotton.SetAsBox(800.0f, 5.0f);
b2FixtureDef GroundBoxFixDefBotton;
GroundBoxFixDefBotton.shape= &groundBoxBotton;
GroundBoxFixDefBotton.density=0.0f;
groundBodyBotton->CreateFixture(&GroundBoxFixDefBotton);

groundBodyDefLeft.type= b2_staticBody;
groundBodyDefLeft.position.Set(5,-600);
b2Body* groundBodyLeft = world->CreateBody(&groundBodyDefLeft);
b2PolygonShape groundBoxLeft;                                 
groundBoxLeft.SetAsBox(5.0f, 600.0f);
groundBodyLeft->CreateFixture(&groundBoxLeft, 0.0f); 

groundBodyDefRight.type= b2_staticBody;
groundBodyDefRight.position.Set(1595,-600);
b2Body* groundBodyRight = world->CreateBody(&groundBodyDefRight);
b2PolygonShape groundBoxRight;                                 
groundBoxRight.SetAsBox(5.0f, 600.0f);
groundBodyRight->CreateFixture(&groundBoxRight, 0.0f); 


b2BodyDef bodyDefBall;
bodyDefBall.type = b2_dynamicBody;
bodyDefBall.position.Set(xBall, yBall);
b2Body* BodyBall1 = world->CreateBody(&(bodyDefBall));
b2CircleShape circle;
circle.m_p.Set(xBall, yBall);
circle.m_radius = radius;
b2FixtureDef fixtureDefBall;
fixtureDefBall.density = 100.0f;
fixtureDefBall.friction = 0.3f;
fixtureDefBall.shape = &circle;
BodyBall1->CreateFixture(&(fixtureDefBall));




/* float w=0.1;
BodyBall1->SetAngularVelocity(w);
*/







/*
b2PolygonShape groundBox2;
groundBox2.SetAsBox(800.0f, 5.0f, b2Vec2(800, -5), 0);
groundBody->CreateFixture(&groundBox2, 0.0f);              //Obere Wand
b2PolygonShape groundBox3;
groundBox3.SetAsBox(800.0f, 5.0f, b2Vec2(800, -1195), 0);
groundBody->CreateFixture(&groundBox3, 0.0f);              //Linke Wand
b2PolygonShape groundBox4;
groundBox4.SetAsBox(1595.0f, 600.0f, b2Vec2(1595, -600), 0);
groundBody->CreateFixture(&groundBox4, 0.0f);              //Untere Wand
/b2PolygonShape groundBox; */

qDebug() << "Zumindest die Welt erschaffen";

timeStep = 1.0f /10.0f;
velocityIterations = 10;
positionIterations = 8;
/*
b2Body* BodyBalken1 = world.CreateBody(&(balken1->bodyDefBalken));
BodyBalken1->CreateFixture(&(balken1->BalkenBox), 0.0f); //Balken in Box2d Simulation erstellt

qDebug() << "Bis Balken1 geschafft";

b2Body* BodyBalken2 = world.CreateBody(&(balken2->bodyDefBalken));
BodyBalken2->CreateFixture(&(balken2->BalkenBox), 0.0f); //Balken in Box2d Simulation erstellt

b2Body* BodyBalken3 = world.CreateBody(&(balken3->bodyDefBalken));
BodyBalken3->CreateFixture(&(balken3->BalkenBox), 0.0f); //Balken in Box2d Simulation erstellt

qDebug() << "Wow, selbst Balken 3 hats geschafft";
*/
//b2Body* BodyBall1 = world.CreateBody(&(Ball1->bodyDefBall));
//BodyBall1->CreateFixture(&(Ball1->fixtureDefBall)); //Ball in Box2d Simulation erstellt

qDebug() << "Ball, bist du das Problem??...Scheint so";


for (int32 i = 0; i < 600; ++i)
{
    world->Step(timeStep, velocityIterations, positionIterations);
    b2Vec2 positionBall = BodyBall1->GetPosition();


    float angle = BodyBall1->GetAngle();
    std::cout<< positionBall.x<<" "<< positionBall.y<<" "<< angle<< std::endl;

    b2Vec2 positionBalken = groundBodyBotton->GetPosition();
    float angleBalken = groundBodyBotton->GetAngle();

    std::cout<< positionBalken.x<<" "<< positionBalken.y<<" "<< angleBalken<< std::endl;

   //std::cout<<BodyBall1->beginContact<<

    Ball1->setPos(positionBall.x, -1*positionBall.y );
}


}
