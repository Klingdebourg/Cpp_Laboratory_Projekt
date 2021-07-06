#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "balken.h"

class Level2: public Level{
public:
    /**
     * @brief Level2 constructor
     * @param game given to Level 2 to be handed to level (parent)
     *
     * Graphics for Level 2 are drawn
     */
    Level2(Game* game);

};

#endif // LEVEL2_H
