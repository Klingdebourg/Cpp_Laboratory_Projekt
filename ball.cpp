#include "ball.h"
#include "maske.h"
#include "virus.h"



Ball::Ball() {
    //creates an ellipse with given size at origin in scene coordinates
    setRect(0, 0, BALL_DIAM, BALL_DIAM);
    //moves the transformation point to the middle of the circle
    setTransformOriginPoint(QPointF(BALL_DIAM/2, BALL_DIAM/2));


}

//für move Funktion

void move(){
    ///Liste mit kollidierenden Elementen erzeugen
    QList <QGraphicsItem *> colliding_items = collidingItems();
    ///Liste durchgehen und checken, ob Item eine Maske oder Virus ist
    int n = colliding_items.size();
    for (int i = 0; i< n; i++){
        for (int j = 0; j< n; j++){
            ///falls Maske: Maske entfernen, Maskecounter hochsetzen
            if ((typeid(*(colliding_items[i])) == typeid(Maske)) && (typeid(*(colliding_items[j])) == typeid(Ball))){
                scene -> removeItem(colliding_items[i]);
                delete colliding_items[i];
                masken_counter += 1;
            }
            if ((typeid(*(colliding_items[i])) == typeid(Virus)) && (typeid(*(colliding_items[j])) == typeid(Ball))){
            ///Spiel beenden
                scene -> clear();
            /// Text "du hast gewonnen" + Highscore

            }
        }
    }
}
