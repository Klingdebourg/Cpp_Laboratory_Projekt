
#ifndef LEVEL2_H
#define LEVEL2_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "balken.h"
#include "virus.h"
#include "maske.h"
#include "feder.h"
#include "counter.h"

#include <box2d/box2d.h>



class Level2: public QGraphicsView
{
public:
    Level2();
    QGraphicsScene* scene;

    float timeStep;
    int32 velocityIterations;
    int32 positionIterations;
};

#endif // LEVEL2_H
