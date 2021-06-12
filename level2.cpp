#include "level2.h"



Game* game2;

Level2::Level2(Game* game, QWidget* parent)
{
//create the scene
scene2 = new QGraphicsScene();
game2 = game;
setScene(scene2);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(WINDOW_W,WINDOW_H);
scene2->setSceneRect(0,0,WINDOW_W,WINDOW_H);
scene2->addLine(0,100,WINDOW_W,100);


//Add title Level 2
QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Level 2"));
QFont titleFont("comic sans",30);
titleText->setDefaultTextColor(Qt::cyan);
titleText->setFont(titleFont);
int txPos = this->width()/2 - titleText->boundingRect().width()/2;
int tyPos = 5;
titleText->setPos(txPos,tyPos);
scene2->addItem(titleText);


//Create the objects for the levels
Balken* balken1 = new Balken(600,1000,0,300, statisch);
Balken* balken2 = new Balken(300,400,0,300, rotatorisch);
Balken* balken3 = new Balken(1000,600,0,300, translatorisch);
//Virus* virus = new Virus(1000,1000);
Ball* ball = new Ball();
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT, *ball);
counter* counter1 = new counter;
counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
//Foehn* foehn = new foehn;
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
scene2->addItem(balken1);
scene2->addItem(balken2);
scene2->addItem(balken3);
//scene->addItem(virus);
scene2->addItem(ball);
scene2->addItem(feder);
scene2->addItem(counter1);
//scene->addItem(foehn);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);


//Pause-Button
Button* pause = new Button(QString("||"));
pause->setRect(0,0,100,100);
connect(pause, SIGNAL(clicked()),this,SLOT(pause()));
scene2->addItem(pause);
}

QGraphicsView* pausepic;
QGraphicsScene* pausemenu;
void Level2::pause(){
    //Szene einfrieren -> box2d??

    //new scene
    pausepic = new QGraphicsView;
    pausemenu = new QGraphicsScene();

    pausepic->setScene(pausemenu);
    pausepic->show();
    pausepic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic->setFixedSize(WINDOW_W/2,WINDOW_H/2);
    pausemenu->setSceneRect(0,0,WINDOW_W/2,WINDOW_H/2);

    QGraphicsTextItem* pausetext = new QGraphicsTextItem;
    pausetext->setPlainText(QString("Du hast auf Pause gedrückt, was möchtest du machen:"));
    pausetext->setDefaultTextColor(Qt::blue);
    pausetext->setPos(pausemenu->width()/5,100);
    pausemenu->addItem(pausetext);

    Button* zurueck = new Button(QString("Zurück zur Levelübersicht"));
    connect(zurueck, SIGNAL(clicked()),this,SLOT(Zurueck()));
    zurueck->setRect(0,0,300,50);
    zurueck->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+100);
    pausemenu->addItem(zurueck);

    Button* redo = new Button(QString("Den Level erneut starten"));
    connect(redo, SIGNAL(clicked()),this,SLOT(Redo()));
    redo->setRect(0,0,300,50);
    redo->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+200);
    pausemenu->addItem(redo);
}

void Level2::Zurueck()
{
game2->show();
game2->levelmenu();
pausemenu->deleteLater();
pausepic->deleteLater();
this->deleteLater();
}

void Level2::Redo()
{
    Level2* level2 = new Level2(game2);
    pausemenu->deleteLater();
    pausepic->deleteLater();
    this->deleteLater();
    level2->show();
}
