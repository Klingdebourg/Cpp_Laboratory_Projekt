#include "ball.h"
#include "maske.h"



Ball::Ball() {
    //creates an ellipse with given size at origin in scene coordinates
    setRect(0, 0, BALL_DIAM, BALL_DIAM);
    //moves the transformation point to the middle of the circle
    setTransformOriginPoint(QPointF(BALL_DIAM/2, BALL_DIAM/2));


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
