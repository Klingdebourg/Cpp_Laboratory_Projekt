#include "level1.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include "ball.h"

Level1::Level1()
{
qDebug() << "Level 1 erstellt.";

scene = new QGraphicsScene();
setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(WINDOW_W,WINDOW_H);
scene->setSceneRect(0,0,WINDOW_W,WINDOW_H);

Balken *Balken1 = new Balken(750, 1100, 0, 100);
scene-> addItem(Balken1);

Ball *BallBsp= new Ball(750, 100, 50);
scene-> addItem(BallBsp);




show();

}

void Level1::Init(){


}
