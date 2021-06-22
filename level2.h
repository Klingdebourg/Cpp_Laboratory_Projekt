#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "balken.h"
#include "feder.h"
#include "foehn.h"

class Level2: public Level{
public:
    Level2(Game* game);
    Element* balken1;
    Element* balken2;
    Element* balken3;
    Element* foehn;

};

#endif // LEVEL2_H
