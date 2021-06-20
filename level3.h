#ifndef LEVEL3_H
#define LEVEL3_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "level.h"
#include "balken.h"
#include "foehn.h"

class Level3: public Level{
public:
    Level3(Game* game);
    Balken* balken1;
    Balken* balken2;
    Balken* balken3;
    Foehn* foehn1;
    Foehn* foehn2;
};

#endif // LEVEL3_H
