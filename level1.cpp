#include "level1.h"



Game* game1;

Level1::Level1(Game* game, QWidget* parent)
{
//create the scene
scene1 = new QGraphicsScene(this);
game1 = game;
setScene(scene1);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(WINDOW_W,WINDOW_H);
scene1->setSceneRect(0,0,WINDOW_W,WINDOW_H);
scene1->addLine(0,100,WINDOW_W,100);


//Add title Level 2
QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Level 1"));
QFont titleFont("comic sans",30);
titleText->setDefaultTextColor(Qt::cyan);
titleText->setFont(titleFont);
int txPos = this->width()/2 - titleText->boundingRect().width()/2;
int tyPos = 5;
titleText->setPos(txPos,tyPos);
scene1->addItem(titleText);


//Create the objects for the levels
Balken* balken1 = new Balken(650,900,0,300);
//Virus* virus = new Virus(1000,1000);
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT);
counter* counter1 = new counter;
counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
scene1->addItem(balken1);
//scene->addItem(virus);
scene1->addItem(feder);
scene1->addItem(counter1);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);


//Pause-Button
Button* pause = new Button(QString("||"));
pause->setRect(0,0,100,100);
connect(pause, SIGNAL(clicked()),this,SLOT(pause()));
scene1->addItem(pause);
}

QGraphicsView* pausepic1;
QGraphicsScene* pausemenu1;
void Level1::pause(){
    //Szene einfrieren -> box2d??

    //new scene
    pausepic1 = new QGraphicsView;
    pausemenu1 = new QGraphicsScene();

    pausepic1->setScene(pausemenu1);
    pausepic1->show();
    pausepic1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic1->setFixedSize(WINDOW_W/2,WINDOW_H/2);
    pausemenu1->setSceneRect(0,0,WINDOW_W/2,WINDOW_H/2);

    QGraphicsTextItem* pausetext = new QGraphicsTextItem;
    pausetext->setPlainText(QString("Du hast auf Pause gedrückt, was möchtest du machen:"));
    pausetext->setDefaultTextColor(Qt::blue);
    pausetext->setPos(pausemenu1->width()/5,100);
    pausemenu1->addItem(pausetext);

    Button* zurueck = new Button(QString("Zurück zur Levelübersicht"));
    connect(zurueck, SIGNAL(clicked()),this,SLOT(Zurueck()));
    zurueck->setRect(0,0,300,50);
    zurueck->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+100);
    pausemenu1->addItem(zurueck);

    Button* redo = new Button(QString("Den Level erneut starten"));
    connect(redo, SIGNAL(clicked()),this,SLOT(Redo()));
    redo->setRect(0,0,300,50);
    redo->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+200);
    pausemenu1->addItem(redo);
}

void Level1::Zurueck()
{
game1->show();
game1->levelmenu();
pausemenu1->deleteLater();
pausepic1->deleteLater();
this->deleteLater();
}

void Level1::Redo()
{
    Level1* level1 = new Level1(game1);
    pausemenu1->deleteLater();
    pausepic1->deleteLater();
    this->deleteLater();
    level1->show();
}
