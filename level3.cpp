#include "level3.h"


Level3::Level3(Game* game):Level(game,3)
{

//Create the objects for the levels
balken1->item = new Balken(550,1000,0,300, rotatorisch);
balken2->item = new Balken(550,400,0,300, statisch);
balken3->item = new Balken(950,650,-45,300, statisch);                //translatorisch?
foehn1->item = new Foehn(balken3->item->x()-75,balken3->item->y()+125);
foehn2->item = new Foehn(balken2->item->x()+650,balken3->item->y()-dynamic_cast<Balken*>(balken3->item)->getLength());
feder->item = new Feder(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT, dynamic_cast<Ball*>(ball->item));


//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1->item);
levelscene->addItem(balken2->item);
levelscene->addItem(balken3->item);
levelscene->addItem(feder->item);
levelscene->addItem(foehn1->item);
levelscene->addItem(foehn2->item);

//Maskenpositionen und Virus
virus->item->setPos(balken2->item->x()+dynamic_cast<Balken*>(balken2->item)->getLength()/2-50,balken2->item->y()-100);
maske1->item->setPos(balken1->item->x()+dynamic_cast<Balken*>(balken1->item)->getLength()-50,virus->item->y()+250);
maske2->item->setPos(balken3->item->x()+dynamic_cast<Balken*>(balken3->item)->getLength()/2,balken3->item->y()-150);
maske3->item->setPos(balken3->item->x(), virus->item->y()-100);

}
