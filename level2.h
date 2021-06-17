
#ifndef LEVEL2_H
#define LEVEL2_H


#include "balken.h"
#include "virus.h"
#include "maske.h"
#include "feder.h"
#include "counter.h"
#include "level.h"
#include "game.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class Game;
class Level;

class Level2 : public Level
{
    Q_OBJECT
public:
    Level2(Game* game,int type = 2);
};

#endif // LEVEL2_H
