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
    world = new b2World(b2Vec2(0.0f, -10.0f));
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

    ball = new Element();
    ball->item = new Ball();
    ball->bodyDef = new b2BodyDef();
    ball->bodyDef->type = b2_dynamicBody;
    //ball->bodyDef->position.Set(0, 0);
    ball->body = world->CreateBody(ball->bodyDef);
    ball->shape = new b2CircleShape();
    dynamic_cast<b2CircleShape*>(ball->shape)->m_p.Set(0, 0);
    ball->shape->m_radius = BALL_DIAM/2;
    ball->fixture = new b2FixtureDef();
    ball->fixture->density = BALL_DENSITY;
    ball->fixture->friction = BALL_FRICTION;
    ball->fixture->restitution = BALL_RESTITUTION;
    ball->fixture->shape = ball->shape;
    ball->body->CreateFixture(ball->fixture);
    levelscene -> addItem(ball->item);


    maske1 = new Element();
    maske1->item = new Maske(0, 0);
    maske1->bodyDef = new b2BodyDef();
    maske1->body = world->CreateBody(ball->bodyDef);
    maske1->shape = new b2PolygonShape();
    maske1->fixture = new b2FixtureDef();
    levelscene -> addItem(maske1->item);

    maske2 = new Element();
    maske2->item = new Maske(0, 0);
    maske2->bodyDef = new b2BodyDef();
    maske2->body = world->CreateBody(ball->bodyDef);
    maske2->shape = new b2PolygonShape();
    maske2->fixture = new b2FixtureDef();
    levelscene -> addItem(maske2->item);

    maske3 = new Element();
    maske3->item = new Maske(0, 0);
    maske3->bodyDef = new b2BodyDef();
    maske3->body = world->CreateBody(ball->bodyDef);
    maske3->shape = new b2PolygonShape();
    maske3->fixture = new b2FixtureDef();
    levelscene -> addItem(maske3->item);

    virus = new Element();
    virus->item = new Virus(0,0);
    virus->bodyDef = new b2BodyDef();
    virus->body = world->CreateBody(ball->bodyDef);
    virus->shape = new b2CircleShape();
    virus->fixture = new b2FixtureDef();
    levelscene -> addItem(virus->item);

    feder = new Element();
    feder->item = new Feder(0, 0);
    feder->bodyDef = new b2BodyDef();
    feder->body = world->CreateBody(feder->bodyDef);
    feder->shape = new b2PolygonShape();
    feder->fixture = new b2FixtureDef();
    levelscene->addItem(feder->item);

    //Pause-Button
    Button* pause = new Button(QString("||"));
    pause->setRect(0,0,100,100);
    connect(pause, SIGNAL(clicked()),this,SLOT(pause()));
    levelscene->addItem(pause);

    pausepic = new QGraphicsView;
    pausemenu = new QGraphicsScene();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Interaktion()));
    timer -> start(TIME_STEP*1000);

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

    Button* haupt = new Button(QString("Zum Hauptmenü"));
    connect(haupt, SIGNAL(clicked()),this,SLOT(Hauptmenu()));
    haupt->setRect(0,0,300,50);
    haupt->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+300);
    pausemenu->addItem(haupt);
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

void Level::Hauptmenu()
{
    levelgame->show();
    levelgame->displayMainMenu();
    pausemenu->deleteLater();
    pausepic->deleteLater();
    this->deleteLater();
}

///Prüft, ob die Items, welche in der Scene sind kollidieren und handelt je nach Art des Items; Interaktion mit Box2D
void Level::Interaktion(){
    //@Lukas: hier Interaktion mit Box2d
    if (!dynamic_cast<Feder*>(feder->item)->getBallAttached()) {
        world->Step(TIME_STEP, VEL_ITER, POS_ITER);
        ballStep = ball->body->GetPosition();
        ball->item->setPos(QPointF(ballStep.x, WINDOW_H-ballStep.y));
        qDebug() << ballStep.x << " " << ballStep.y;

    }







  ///Kollisionsabfrage
    ///In Ball abfragen, was mit Ball kollidiert
    int colliding_item = dynamic_cast<Ball*>(ball->item)->collidingItem(dynamic_cast<Maske*>(maske1->item),
                                                                        dynamic_cast<Maske*>(maske2->item),
                                                                        dynamic_cast<Maske*>(maske3->item),
                                                                        dynamic_cast<Virus*>(virus->item));
    if (colliding_item == 1){
        qDebug("Maske1 wird berührt");
        levelscene -> removeItem(maske1->item);
        Counter -> increase();
        return;
    } else if (colliding_item == 2){
        levelscene -> removeItem(maske2->item);
        Counter -> increase();
        return;
    } else if (colliding_item == 3){
        levelscene -> removeItem(maske3->item);
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
