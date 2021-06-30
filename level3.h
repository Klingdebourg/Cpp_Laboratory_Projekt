#ifndef LEVEL3_H
#define LEVEL3_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "level.h"
#include "balken.h"

class Level3: public Level{
public:
    /**
     * @brief Level3 constructor
     * @param game given to Level 3 to be handed to level (parent)
     *
     * Graphics for Level 3 are drawn
     */
    Level3(Game* game);

};

#endif // LEVEL3_H
