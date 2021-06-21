#ifndef LEVEL3_H
#define LEVEL3_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "level.h"
#include "balken.h"
#include "foehn.h"
#include "feder.h"

class Level3: public Level{
public:
    Level3(Game* game);
    Balken* balken1;
    Balken* balken2;
    Balken* balken3;
    Foehn* foehn1;
    Foehn* foehn2;
    Feder* feder;
};

#endif // LEVEL3_H
