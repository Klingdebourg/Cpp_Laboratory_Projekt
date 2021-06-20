#include "level2.h"
#include "balken.h"
#include "feder.h"
#include <QDebug>
#include "foehn.h"


Level2::Level2(Game* game):Level(game, 2)
{

//Create the objects for the levels
Balken* balken1 = new Balken(600,1000,0,300, rotatorisch);
Balken* balken2 = new Balken(300,400,0,300, statisch);
Balken* balken3 = new Balken(1000,600,0,300, statisch);             //translatorisch?

//Virus* virus = new Virus(1000,1000);
//Ball* ball = new Ball();
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT);
//counter* counter1 = new counter;
//counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
Foehn* foehn = new Foehn(700, 0);
//Maske* maske1 = new Maske(0, 0);
//Maske* maske2 = new Maske(0, 0);
//Maske* maske3 = new Maske(0, 0);

//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
levelscene->addItem(balken2);
levelscene->addItem(balken3);
//levelscene->addItem(virus);

//levelscene->addItem(ball);
levelscene->addItem(feder);
//levelscene->addItem(Counter);
levelscene->addItem(foehn);
//levelscene->addItem(maske1);
//levelscene->addItem(maske2);
//levelscene->addItem(maske3);

}

