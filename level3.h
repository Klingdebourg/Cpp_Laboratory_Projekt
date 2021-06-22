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
    Element* balken1;
    Element* balken2;
    Element* balken3;
    Element* foehn1;
    Element* foehn2;
};

#endif // LEVEL3_H
