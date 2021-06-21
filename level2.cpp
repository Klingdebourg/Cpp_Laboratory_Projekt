#include "level2.h"

Level2::Level2(Game* game):Level(game, 2)
{

//Create the objects for the levels
balken1->item = new Balken(600,1000,0,300, rotatorisch);
balken2->item = new Balken(300,400,0,300, statisch);
balken3->item = new Balken(1000,600,0,300, statisch);             //translatorisch?
feder->item = new Feder(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT, dynamic_cast<Ball*>(ball->item));
foehn->item = new Foehn(balken2->item->x()-100, balken2->item->y()-100);


//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1->item);
levelscene->addItem(balken2->item);
levelscene->addItem(balken3->item);
levelscene->addItem(feder->item);
levelscene->addItem(foehn->item);

//Maskenposition und Virus position setzen
virus->item->setPos(balken3->item->x()+dynamic_cast<Balken*>(balken3->item)->getLength(),balken3->item->y()-150);
maske1->item->setPos(balken3->item->x()-250,balken3->item->y()-50);
maske2->item->setPos(virus->item->x()-250,virus->item->y());
maske3->item->setPos(balken2->item->x()+dynamic_cast<Balken*>(balken2->item)->getLength()/2-25,balken2->item->y()-100);

}

