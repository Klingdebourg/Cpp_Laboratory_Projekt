#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "balken.h"



class Level1: public Level
{

public:
    Level1(Game* game);

    Element* balken1;
};

#endif // LEVEL1_H
