#include <QDebug>
#include <QGraphicsTextItem>
#include "ball.h"
#include "Box2d_Playground.h"

Playground::Playground1()
{
qDebug() << "Playground1 erstellt";

scene = new QGraphicsScene();
setScene(scene);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(WINDOW_W,WINDOW_H);
scene->setSceneRect(0,0,WINDOW_W,WINDOW_H);




}
