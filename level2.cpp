#include "level2.h"

Level2::Level2(Game* game):Level(game, 2)
{

//Create the objects for the levels
balken1 = new Balken(600,1000,0,300, rotatorisch);
balken2 = new Balken(300,400,0,300, statisch);
balken3 = new Balken(1000,600,0,300, statisch);             //translatorisch?
feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT, *ball);
foehn = new Foehn(balken2->x()-100, balken2->y()-100);


//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
levelscene->addItem(balken2);
levelscene->addItem(balken3);
levelscene->addItem(feder);
levelscene->addItem(foehn);

//Maskenposition und Virus position setzen
virus->setPos(balken3->x()+balken3->getLength(),balken3->y()-150);
maske1->setPos(balken3->x()-250,balken3->y()-50);
maske2->setPos(virus->x()-250,virus->y());
maske3->setPos(balken2->x()+balken2->getLength()/2-25,balken2->y()-100);

}

