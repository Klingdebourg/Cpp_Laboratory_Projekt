#include "level3.h"
#include "balken.h"
#include "feder.h"


Game* game3;

Level3::Level3(Game* game):Level(game,3)
{

//Create the objects for the levels
Balken* balken1 = new Balken(550,1000,0,300, rotatorisch);
Balken* balken2 = new Balken(550,400,0,300, statisch);
Balken* balken3 = new Balken(950,650,-45,300, statisch);                //translatorisch?
//Ball* ball = new Ball();
//Foehn* foehn1 = new Foehn();
//Foehn* foehn2 = new Foehn();
//Virus* virus = new Virus(1000,1000);
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT);
//counter* counter1 = new counter;
//counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
levelscene->addItem(balken2);
levelscene->addItem(balken3);
//scene->addItem(virus);
levelscene->addItem(feder);
//levelscene->addItem(counter1);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);
}
