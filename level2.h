#ifndef LEVEL2_H
#define LEVEL2_H


#include "level.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "balken.h"
#include "maske.h"
#include "feder.h"

class Level2: public Level {
public:
    Level2(Game* game);
    Element* balken1;
    Element* balken2;
    Element* balken3;
    Element* feder;
    Element* foehn;
};

#endif // LEVEL2_H
