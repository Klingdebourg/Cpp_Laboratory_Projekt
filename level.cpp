#include "level.h"
#include "button.h"
#include "definitions.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include <QTimer>
#include <QDebug>

Level::Level(Game* game,int type, QWidget* parent):QGraphicsView(parent){
    levelscene = new QGraphicsScene(this);
    levelgame = game;
    level = type;
    setScene(levelscene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_W,WINDOW_H);
    levelscene->setSceneRect(0,0,WINDOW_W,WINDOW_H);
    levelscene->addLine(0,100,WINDOW_W,100);

    if (level == 1 ){
        text= "Level 1";
    }
    if(level == 2){
        text = "Level 2";
    }
    if(level == 3){
        text = "Level 3";
    }
    QGraphicsTextItem* titleText = new QGraphicsTextItem(text);
    QFont titleFont("comic sans",30);
    titleText->setDefaultTextColor(Qt::cyan);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 5;
    titleText->setPos(txPos,tyPos);
    levelscene->addItem(titleText);

    ball = new Ball();
    maske1 = new Maske(0,0);
    maske2 = new Maske(400,0);
    maske3 = new Maske(600,0);
    virus = new Virus(800,0);
    levelscene -> addItem(ball);
    levelscene -> addItem(maske1);
    levelscene -> addItem(maske2);
    levelscene -> addItem(maske3);
    levelscene -> addItem(virus);

    //Pause-Button
    Button* pause = new Button(QString("||"));
    pause->setRect(0,0,100,100);
    connect(pause, SIGNAL(clicked()),this,SLOT(pause()));
    levelscene->addItem(pause);

    pausepic = new QGraphicsView;
    pausemenu = new QGraphicsScene();

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Interaktion()));
    timer -> start(1/60*1000);

    Counter = new counter;
    Counter->setPos(WINDOW_W-Counter->boundingRect().width(),y());
    levelscene -> addItem(Counter);

}


void Level::pause(){
    //Szene einfrieren -> box2d??

    //new scene

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

void Level::Zurueck()
{
levelgame->show();
levelgame->levelmenu();
pausemenu->deleteLater();
pausepic->deleteLater();
this->deleteLater();
}

void Level::Redo()
{
    pausemenu->deleteLater();
    pausepic->deleteLater();
    this->deleteLater();

    if (level == 1 ){
        Level1* level1 = new Level1(levelgame);
        level1->show();
    }
    if(level == 2){
        Level2* level2 = new Level2(levelgame);
        level2->show();
    }
    if(level == 3){
        Level3* level3 = new Level3(levelgame);
        level3->show();
    }
}

///Prüft, ob die Items, welche in der Scene sind kollidieren und handelt je nach Art des Items; Interaktion mit Box2D
void Level::Interaktion(){
    //@Lukas: hier Interaktion mit Box2d








  ///Kollisionsabfrage
    ///In Ball abfragen, was mit Ball kollidiert
    int colliding_item = ball -> collidingItem(maske1, maske2, maske3, virus);
    if (colliding_item == 1){
        qDebug("Maske1 wird berührt");
        levelscene -> removeItem(maske1);
        Counter -> increase();
        return;
    } else if (colliding_item == 2){
        levelscene -> removeItem(maske2);
        Counter -> increase();
        return;
    } else if (colliding_item == 3){
        levelscene -> removeItem(maske3);
        Counter -> increase();
        return;
    }  else if (colliding_item == 4){
        ///Spiel beenden
        levelscene -> clear();
        /// Text "du hast gewonnen" + Highscore
    } else if (colliding_item == 5){
        qDebug("Nichts wird berührt");
        return;
    }

//    ///Liste durchgehen und checken, ob Item eine Maske oder Virus ist
//    int n = colliding_items_level.size();
//    for (int i = 0; i< n; i++){
//        for (int j = 0; j< n; j++){
//            ///falls Maske: Maske entfernen, Maskecounter hochsetzen
//            if ((typeid(*(colliding_items_level[i])) == typeid(Maske)) && (typeid(*(colliding_items_level[j])) == typeid(Ball))){
//                levelscene -> removeItem(colliding_items_level[i]);
//                delete colliding_items_level[i];
//                Counter -> increase();
//                return;
//            }
//            else if ((typeid(*(colliding_items_level[i])) == typeid(Virus)) && (typeid(*(colliding_items_level[j])) == typeid(Ball))){
//            ///Spiel beenden
//                levelscene -> clear();
//                return;
//            /// Text "du hast gewonnen" + Highscore

//            }
//            else return;
//        }
//    }
}

