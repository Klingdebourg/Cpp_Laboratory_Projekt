#include "level1.h"



Level1::Level1(Game* game):Level(game,1)
{

//Create the objects for the levels
    balken1 = new Element();
    balken1->item = new Balken(800,900,0,300,rotatorisch);
    balken1->bodyDef = new b2BodyDef();
    balken1->body = world->CreateBody(balken1->bodyDef);
    balken1->fixture = new b2FixtureDef();

    feder = new Element();
    feder->item = new Feder(balken1->item->x()+(balken1->item->boundingRect().width() - FEDER_WIDTH)/2, balken1->item->y()-FEDER_HEIGHT, dynamic_cast<Ball*>(ball->item));
    feder->bodyDef = new b2BodyDef();
    feder->body = world->CreateBody(balken1->bodyDef);
    feder->fixture = new b2FixtureDef();


    //Add the objects/items to the scene to be visualized
    levelscene->addItem(balken1->item);
    levelscene->addItem(feder->item);

    //Position der Masken und des Virus festlegen
    virus->item->setPos(balken1->item->x()-600,balken1->item->y()-725);
    maske1->item->setPos(balken1->item->x(),balken1->item->y()-275);
    maske2->item->setPos(balken1->item->x()-175,balken1->item->y()-450);
    maske3->item->setPos(balken1->item->x()-350,balken1->item->y()-575);

}
