#include "level3.h"



Game* game3;

Level3::Level3(Game* game, QWidget* parent)
{
//create the scene
scene3 = new QGraphicsScene(this);
game3 = game;
setScene(scene3);
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(WINDOW_W,WINDOW_H);
scene3->setSceneRect(0,0,WINDOW_W,WINDOW_H);
scene3->addLine(0,100,WINDOW_W,100);


//Add title Level 2
QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Level 3"));
QFont titleFont("comic sans",30);
titleText->setDefaultTextColor(Qt::cyan);
titleText->setFont(titleFont);
int txPos = this->width()/2 - titleText->boundingRect().width()/2;
int tyPos = 5;
titleText->setPos(txPos,tyPos);
scene3->addItem(titleText);


//Create the objects for the levels
Balken* balken1 = new Balken(550,1000,0,300);
Balken* balken2 = new Balken(550,400,0,300);
Balken* balken3 = new Balken(950,650,-45,300);
//Ball* ball = new Ball();
//Foehn* foehn1 = new Foehn();
//Foehn* foehn2 = new Foehn();
//Virus* virus = new Virus(1000,1000);
Feder* feder = new Feder(balken1->x()+(balken1->boundingRect().width() - FEDER_WIDTH)/2, balken1->y()-FEDER_HEIGHT);
counter* counter1 = new counter;
counter1->setPos(WINDOW_W-counter1->boundingRect().width(),y());
//Maske* maske1 = new Maske;
//Maske* maske2 = new Maske;
//Maske* maske3 = new Maske;

//Add the objects/items to the scene to be visualized
scene3->addItem(balken1);
scene3->addItem(balken2);
scene3->addItem(balken3);
//scene->addItem(virus);
scene3->addItem(feder);
scene3->addItem(counter1);
//scene->addItem(maske1);
//scene->addItem(maske2);
//scene->addItem(maske3);


//Pause-Button
Button* pause = new Button(QString("||"));
pause->setRect(0,0,100,100);
connect(pause, SIGNAL(clicked()),this,SLOT(pause()));
scene3->addItem(pause);
}

QGraphicsView* pausepic3;
QGraphicsScene* pausemenu3;
void Level3::pause(){
    //Szene einfrieren -> box2d??

    //new scene
    pausepic3 = new QGraphicsView;
    pausemenu3 = new QGraphicsScene();

    pausepic3->setScene(pausemenu3);
    pausepic3->show();
    pausepic3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic3->setFixedSize(WINDOW_W/2,WINDOW_H/2);
    pausemenu3->setSceneRect(0,0,WINDOW_W/2,WINDOW_H/2);

    QGraphicsTextItem* pausetext = new QGraphicsTextItem;
    pausetext->setPlainText(QString("Du hast auf Pause gedrückt, was möchtest du machen:"));
    pausetext->setDefaultTextColor(Qt::blue);
    pausetext->setPos(pausemenu3->width()/5,100);
    pausemenu3->addItem(pausetext);

    Button* zurueck = new Button(QString("Zurück zur Levelübersicht"));
    connect(zurueck, SIGNAL(clicked()),this,SLOT(Zurueck()));
    zurueck->setRect(0,0,300,50);
    zurueck->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+100);
    pausemenu3->addItem(zurueck);

    Button* redo = new Button(QString("Den Level erneut starten"));
    connect(redo, SIGNAL(clicked()),this,SLOT(Redo()));
    redo->setRect(0,0,300,50);
    redo->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+200);
    pausemenu3->addItem(redo);
}

void Level3::Zurueck()
{
game3->show();
game3->levelmenu();
pausemenu3->deleteLater();
pausepic3->deleteLater();
this->deleteLater();
}

void Level3::Redo()
{
    Level3* level3 = new Level3(game3);
    pausemenu3->deleteLater();
    pausepic3->deleteLater();
    this->deleteLater();
    level3->show();
}
