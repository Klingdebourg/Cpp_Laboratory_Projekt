#include "level2.h"
#include "balken.h"
#include "virus.h"
#include "maske.h"
#include "feder.h"
#include "counter.h"
#include <QDebug>
#include "virus.h"
#include "foehn.h"



Level2::Level2(Game* game): Level(game, 2)
{

//Create the objects for the levels
Balken* balken1 = new Balken(600,1000,0,300, rotatorisch);
Balken* balken2 = new Balken(300,400,0,300, statisch);
Balken* balken3 = new Balken(1000,600,0,300, statisch);             //translatorisch?

//Virus* virus = new Virus(1000,1000);
Ball* ball = new Ball();
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT, *ball);
counter* counter1 = new counter;
Virus *virus1 = new Virus(100, 100);
Foehn * foehn1 = new Foehn (100,100);
counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
//Foehn* foehn = new foehn;
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
levelscene->addItem(balken2);
levelscene->addItem(balken3);
//scene->addItem(virus);

levelscene->addItem(ball);
levelscene->addItem(feder);
levelscene->addItem(counter1);
//scene->addItem(foehn);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);

}

