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
    Balken* balken1;
    Balken* balken2;
    Balken* balken3;
    Feder* feder;
    Foehn* foehn;

};

#endif // LEVEL2_H
