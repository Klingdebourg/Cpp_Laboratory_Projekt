#include "level1.h"
#include "balken.h"
#include "virus.h"
#include "maske.h"
#include "feder.h"



Level1::Level1(Game* game):Level(game,1)
{


//Create the objects for the levels
Balken* balken1 = new Balken(650,900,0,300,rotatorisch);
//Virus* virus = new Virus(1000,1000);
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT);
Counter->setPos(WINDOW_W-Counter->boundingRect().width(),y());
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
//scene->addItem(virus);
levelscene->addItem(feder);
levelscene->addItem(Counter);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);

}
