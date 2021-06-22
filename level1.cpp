#include "level1.h"



Level1::Level1(Game* game):Level(game,1)
{

//Create the objects for the levels
Balken* balken1 = new Balken(800,900,0,300,rotatorisch);
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT, *ball);
bodyBall->SetTransform(b2Vec2(ball->x(), ball->y()), ball->rotation());


//Add the objects/items to the scene to be visualized
levelscene->addItem(balken1);
levelscene->addItem(feder);

//Position der Masken und des Virus festlegen
virus->setPos(balken1->x()-600,balken1->y()-725);
maske1->setPos(balken1->x(),balken1->y()-275);
maske2->setPos(balken1->x()-175,balken1->y()-450);
maske3->setPos(balken1->x()-350,balken1->y()-575);

}
