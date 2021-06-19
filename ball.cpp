#include "ball.h"
#include "maske.h"


Ball::Ball()
{

}

//für move Funktion

//Liste mit kollidierenden Elementen erzeugen
QList <QGraphicsItem *> colliding_items = collidingItems();
    //Liste durchgehen und checken, ob Item eine Maske oder Virus ist
    for (int i = 0, n = colliding_items.size(); i< n; i++){
        //falls Maske: Maske entfernen, Maskecounter hochsetzen
        if (typeid(*(colliding_items[i]]] == typeid(Maske)){
            scene -> removeItem(colliding_items[i]);
            delete colliding_items[i];
            masken_counter += 1;
        }
        else if (typeid(*(colliding_items[i]]] == typeid(Virus)){
//Spiel beenden

}
