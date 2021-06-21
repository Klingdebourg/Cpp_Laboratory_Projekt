#ifndef LEVEL2_H
#define LEVEL2_H

<<<<<<< HEAD

#include "level.h"
#include <QGraphicsScene>
=======
#include "level.h"
>>>>>>> master
#include <QGraphicsView>
#include <QGraphicsScene>
#include "balken.h"
<<<<<<< HEAD
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
=======
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

>>>>>>> master
};

#endif // LEVEL2_H
