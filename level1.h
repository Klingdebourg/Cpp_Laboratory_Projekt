#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "balken.h"



class Level1: public Level
{

public:
    /**
     * @brief Level1 constructor
     * @param game given to Level 1 to be handed to level(parent)
     *
     * Graphics for Level 1 are drawn
     */
    Level1(Game* game);

};

#endif // LEVEL1_H
