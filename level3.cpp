#include "level3.h"


Level3::Level3(Game* game):Level(game,3)
{

//Create the objects for the levels
balken1 = new Balken(550,1000,0,300, rotatorisch);
balken2 = new Balken(550,400,0,300, statisch);
balken3 = new Balken(950,650,-45,300, statisch);                //translatorisch?
foehn1 = new Foehn(balken3->x()-75,balken3->y()+125);
foehn2 = new Foehn(balken2->x()+650,balken3->y()-balken3->getLength());
feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT, *ball);


//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
levelscene->addItem(balken2);
levelscene->addItem(balken3);
levelscene->addItem(feder);
levelscene->addItem(foehn1);
levelscene->addItem(foehn2);

//Maskenpositionen und Virus
virus->setPos(balken2->x()+balken2->getLength()/2-50,balken2->y()-100);
maske1->setPos(balken1->x()+balken1->getLength()-50,virus->y()+250);
maske2->setPos(balken3->x()+balken3->getLength()/2,balken3->y()-150);
maske3->setPos(balken3->x(), virus->y()-100);

}
