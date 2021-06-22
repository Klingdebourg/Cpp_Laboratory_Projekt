#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "balken.h"
#include "feder.h"



class Level1: public Level
{

public:
    Level1(Game* game);
    Balken* balken1;
    b2BodyDef* bodyDefBalken;
    b2Body* bodyBalken;
    b2FixtureDef* balkenFixtureDef;
    b2PolygonShape* rect;
    Feder* feder;
};

#endif // LEVEL1_H
