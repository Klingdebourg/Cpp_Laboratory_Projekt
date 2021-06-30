#include "level.h"
#include "button.h"
#include "definitions.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QLineEdit>

Level::Level(Game* game,int type, QWidget* parent):QGraphicsView(parent){
    ///create the basic scene for the level
    levelscene = new QGraphicsScene(this);
    levelgame = game;
    level = type;
    setScene(levelscene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_W,WINDOW_H);
    levelscene->setSceneRect(0,0,WINDOW_W,WINDOW_H);
    levelscene->addLine(0,100,WINDOW_W,100);

    //create box2d world with negative gravity of
    world = new b2World(b2Vec2(0.0f, GRAVITY));

    //create a wall for each side of the window
    groundBodyDefTop.position.Set(800,20);
    b2Body* groundBodyTop = world->CreateBody(&groundBodyDefTop);
    b2PolygonShape groundBoxTop;
    groundBoxTop.SetAsBox(900.0f, 5.0f);
    groundBodyTop->CreateFixture(&groundBoxTop, 0.0f);

    groundBodyDefBotton.position.Set(800,1030);
    b2Body* groundBodyBotton = world->CreateBody(&groundBodyDefBotton);
    b2PolygonShape groundBoxBotton;
    groundBoxBotton.SetAsBox(900.0f, 5.0f);
    groundBodyBotton->CreateFixture(&groundBoxBotton, 0.0f);

    groundBodyDefLeft.position.Set(-30,600);
    b2Body* groundBodyLeft = world->CreateBody(&groundBodyDefLeft);
    b2PolygonShape groundBoxLeft;
    groundBoxLeft.SetAsBox(5.0f, 600.0f);
    groundBodyLeft->CreateFixture(&groundBoxLeft, 0.0f);

    groundBodyDefRight.position.Set(1580,600);
    b2Body* groundBodyRight = world->CreateBody(&groundBodyDefRight);
    b2PolygonShape groundBoxRight;
    groundBoxRight.SetAsBox(5.0f, 600.0f);
    groundBodyRight->CreateFixture(&groundBoxRight, 0.0f);

    ///create a button to close the info for each level
    Button* closeinfo = new Button(QString("OK & schließen"));
    connect(closeinfo, SIGNAL(clicked()),this,SLOT(InfoToBeClosed()));
    closeinfo->setRect(0,0,150,50);

    bounds=new QGraphicsRectItem;

    ///depending on the level, set the title text of the level and create the info
    if (level == 1 ){
        text= "Level 1";
        Info = new info(1,closeinfo, bounds);
        levelscene->addItem(Info);
    }
    if(level == 2){
        text = "Level 2";
        closeinfo->setPos(0,0);
        Info = new info(2,closeinfo, bounds);
        levelscene->addItem(Info);

    }
    if(level == 3){
        text = "Level 3";
        closeinfo->setPos(0,0);
        Info = new info(3,closeinfo, bounds);
        levelscene->addItem(Info);

    }
    levelscene->addItem(bounds);

    ///draw the title
    QGraphicsTextItem* titleText = new QGraphicsTextItem(text);
    QFont titleFont("comic sans",30);
    titleText->setDefaultTextColor(Qt::cyan);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 5;
    titleText->setPos(txPos,tyPos);
    levelscene->addItem(titleText);

    ///create the basic elements of every level
    ball = new Element(BALL);
    ball->body = world->CreateBody(ball->bodyDef);
    ball->body->CreateFixture(ball->fixture);
    levelscene -> addItem(ball->item);

    feder = new Element(FEDER);
    //the feder item cannot be genereated in the element-constructor due to the circular include
    feder->item = new Feder(0, 0);
    //feder->body = world->CreateBody(feder->bodyDef);
    //feder->body->CreateFixture(feder->fixture);
    levelscene->addItem(feder->item);

    maske1 = new Element(MASKE);
    maske1->body = world->CreateBody(maske1->bodyDef);
    maske1->body->CreateFixture(maske1->fixture);
    levelscene -> addItem(maske1->item);

    maske2 = new Element(MASKE);
    maske2->body = world->CreateBody(maske2->bodyDef);
    maske2->body->CreateFixture(maske2->fixture);
    levelscene -> addItem(maske2->item);

    maske3 = new Element(MASKE);
    maske3->body = world->CreateBody(maske3->bodyDef);
    maske3->body->CreateFixture(maske3->fixture);
    levelscene -> addItem(maske3->item);

    virus = new Element(VIRUS);
    virus->body = world->CreateBody(virus->bodyDef);
    virus->body->CreateFixture(virus->fixture);
    levelscene -> addItem(virus->item);

    ///create a pause button
    Button* pause = new Button(QString("||"));
    pause->setRect(0,0,100,100);
    connect(pause, SIGNAL(clicked()),this,SLOT(pause()));
    levelscene->addItem(pause);
    isPaused = false;

    pausepic = new QGraphicsView();
    pausemenu = new QGraphicsScene();

    ///create a timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Interaktion()));
    timer -> start(TIME_STEP*1000);

    ///create a counter for the collected masks
    Counter = new counter;
    Counter->setPos(WINDOW_W-Counter->boundingRect().width(),y());
    levelscene -> addItem(Counter);

    ///set the counter needed for the fail condition
    failbedingung=0;

    levelscene->addItem(closeinfo);



}

/**
 * @brief Level::pause to pause the game
 */
void Level::pause(){
    isPaused = true;

    ///create a new scene and view for the pause menu

    pausepic->setScene(pausemenu);
    pausepic->show();
    pausepic->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    pausepic->setFixedSize(WINDOW_W/2,WINDOW_H/2);
    pausemenu->setSceneRect(0,0,WINDOW_W/2,WINDOW_H/2);

    ///draw the title
    QGraphicsTextItem* pausetext = new QGraphicsTextItem;
    pausetext->setPlainText(QString("Du hast auf Pause gedrückt, was möchtest du machen:"));
    pausetext->setDefaultTextColor(Qt::blue);
    pausetext->setPos(pausemenu->width()/5,100);
    pausemenu->addItem(pausetext);

    ///create a return button to get back to the level menu
    Button* zurueck = new Button(QString("Zurück zur Levelübersicht"));
    connect(zurueck, SIGNAL(clicked()),this,SLOT(Zurueck()));
    zurueck->setRect(0,0,300,50);
    zurueck->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+100);
    pausemenu->addItem(zurueck);

    ///create a button to restart the level
    Button* redo = new Button(QString("Den Level erneut starten"));
    connect(redo, SIGNAL(clicked()),this,SLOT(Redo()));
    redo->setRect(0,0,300,50);
    redo->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+200);
    pausemenu->addItem(redo);

    ///create a button to return to the main menu
    Button* haupt = new Button(QString("Zum Hauptmenü"));
    connect(haupt, SIGNAL(clicked()),this,SLOT(Hauptmenu()));
    haupt->setRect(0,0,300,50);
    haupt->setPos(pausetext->x()+pausetext->boundingRect().width()/4, pausetext->y()+300);
    pausemenu->addItem(haupt);
}

/**
 * @brief Level::Zurueck to return to the level menu from pause menu
 */
void Level::Zurueck()
{
    ///call the levelmenu of the game scene and delete everything else
    levelgame->show();
    levelgame->levelmenu();
    pausemenu->deleteLater();
    pausepic->deleteLater();
    this->deleteLater();
}

/**
 * @brief Level::Redo rebuilds the level
 */
void Level::Redo()
{
    ///delete the existing level and depending on the level create a new level object
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
    isPaused = false;
}

/**
 * @brief Level::Hauptmenu to return to the main menu from pause menu
 */
void Level::Hauptmenu()
{
    ///call the main menu and delete everything else
    levelgame->show();
    levelgame->displayMainMenu();
    pausemenu->deleteLater();
    pausepic->deleteLater();
    this->deleteLater();
}


///Prüft, ob die Items, welche in der Scene sind kollidieren und handelt je nach Art des Items; Interaktion mit Box2D

/**
 * @brief Level::Interaktion is called TIME_STEP times per second via a timer
 * first functionality: step the box2d world
 * second fuinctionality: check if the ball collided with any itmes and act accordingly
 */
void Level::Interaktion(){
    ///update the positions of all balken if their Qt appearance has been changed
    updateB2Balken();

    ///account for influence of the foehne
    applyFoehnForces();

    ///update world in box2d (ask new position of ball and apply)
    ///only update if the ball is not attached to the spring
    ///as the ball is the only dynamic item in the world
    if (!dynamic_cast<Feder*>(feder->item)->getBallAttached() && !isPaused) {
        ///calculate the positions of all items after one step in the box2d world
        world->Step(TIME_STEP, VEL_ITER, POS_ITER);

        ///calculate the new position of the ball and apply it
        ballStep = ball->body->GetPosition();
        ball->item->setPos(QPointF(ballStep.x, WINDOW_H-ballStep.y));
    }


    ///Check for position of the ball, if it hasn't changed in 1500 times of calling the method then the game is lost
    if (StopCheck()==true){
        return;}




    ///Kollisionsabfrage
    ///In Ball abfragen, was mit Ball kollidiert
    int colliding_item = dynamic_cast<Ball*>(ball->item)->collidingItem(dynamic_cast<Maske*>(maske1->item),
                                                                        dynamic_cast<Maske*>(maske2->item),
                                                                        dynamic_cast<Maske*>(maske3->item),
                                                                        dynamic_cast<Virus*>(virus->item));
    if (colliding_item == 1){
       // qDebug("Maske1 wird berührt"); +++++++++++++++++++++++++++++++++++++
//        levelscene -> removeItem(maske1->item);
        dynamic_cast<Maske*>(maske1->item)->setPos(0,-100);
        Counter -> increase();
        return;
    } else if (colliding_item == 2){
//        levelscene -> removeItem(maske2->item);
        dynamic_cast<Maske*>(maske2->item)->setPos(0,-100);
        Counter -> increase();
        return;
    } else if (colliding_item == 3){
//        levelscene -> removeItem(maske3->item);
        dynamic_cast<Maske*>(maske3->item)->setPos(0,-100);
        Counter -> increase();
        return;
    }  else if (colliding_item == 4){
        ///Spiel beenden
        timer->stop();
        finalscore = Counter->getscore();
        levelscene->clear();
        Gewonnen();
        return;
        /// Text "du hast gewonnen" + Highscore
    } else if (colliding_item == 5){       
//        qDebug("Nichts wird berührt");
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

void Level::InfoToBeClosed()
{   ///to delete the Info
    Info->OKpressed();
    delete(bounds);
}

void Level::Gewonnen()
{

    ///draw the winning text
    QGraphicsTextItem* winText = new QGraphicsTextItem(QString("Wow. Du hast es geschafft den Virus zu besiegen. Glückwunsch! Du hast es geschafft dabei "+QString::number(finalscore)+ " Maske/n zu sammeln und das in einer Zeit von(Hier einfügen Uhr!)! Was möchtest du jetzt tun?"));

    QFont titleFont("comic sans",10);
    winText->setTextWidth(1000);
    winText->setDefaultTextColor(Qt::darkGreen);
    winText->setFont(titleFont);
    int txPos = levelscene->width()/2 - winText->boundingRect().width()/2;
    int tyPos = WINDOW_H*1/8;
    winText->setPos(txPos,tyPos);
    levelscene->addItem(winText);

    ///create a button to get back to the level menu
    Button* zurueck = new Button(QString("Zurück zur Levelübersicht"));
    connect(zurueck, SIGNAL(clicked()),this,SLOT(Zurueck()));
    zurueck->setRect(0,0,300,50);
    zurueck->setPos(WINDOW_W/8,WINDOW_H/2);
    levelscene->addItem(zurueck);

    ///depending on the level played, create a button to directly play the next one
    if (level == 1 || level == 2){
    Button* next = new Button(QString("Nächster Level"));
    connect(next, SIGNAL(clicked()),this,SLOT(Next()));
    next->setRect(0,0,300,50);
    next->setPos(WINDOW_W*5/8,WINDOW_H/2);
    levelscene->addItem(next);}

    ///create a restart button
    Button* redo = new Button(QString("Den Level erneut starten"));
    connect(redo, SIGNAL(clicked()),this,SLOT(Redo()));
    redo->setRect(0,0,300,50);
    redo->setPos(WINDOW_W/8, WINDOW_H*3/4);
    levelscene->addItem(redo);

    ///create a button to return to the main menu
    Button* haupt = new Button(QString("Zum Hauptmenü"));
    connect(haupt, SIGNAL(clicked()),this,SLOT(Hauptmenu()));
    haupt->setRect(0,0,300,50);
    haupt->setPos(WINDOW_W*5/8, WINDOW_H*3/4);
    levelscene->addItem(haupt);

    ///create a button to save the score
    Button* highscore = new Button(QString("Meinen Score speichern"));
    connect(highscore, SIGNAL(clicked()),this,SLOT(AddScore()));
    highscore->setRect(0,0,300,50);
    highscore->setPos(WINDOW_W*3/8, WINDOW_H*5/8);
    levelscene->addItem(highscore);


}




void Level::Next()
{
    ///depending on the level that was played, delete this level and start the next one
    if(level==1){
        this->deleteLater();
        Level2* level2 = new Level2(levelgame);
        level2->show();
    }
    if(level ==2){
        this->deleteLater();
        Level3* level3 = new Level3(levelgame);
        level3->show();
    }

}


void Level::AddScore()
{
    ///draw the text for the highscore
    levelscene->clear();
    QGraphicsTextItem* enternametitle = new QGraphicsTextItem(QString("Bitte gebe deinen Namen ein und bestätige mit dem Button"));
    QFont titleFont("comic sans",20);
    enternametitle->setFont(titleFont);
    enternametitle->setPos(WINDOW_W/16,WINDOW_H/8);
    levelscene->addItem(enternametitle);

    ///draw the QLineEdit to enter the name of the player
    QLineEdit* input = new QLineEdit();
    QFont textFont("time",15);
    input->setReadOnly(false);
    input->setFixedHeight(100);
    input->setFixedWidth(500);
    input->setFont(textFont);
    input->move(WINDOW_W/3,WINDOW_H/2);
    levelscene->addWidget(input);

    ///draw the score
    QGraphicsTextItem*sc = new QGraphicsTextItem(QString("Dein Score: " + QString::number(finalscore)));
    sc->setPos(WINDOW_W/8,WINDOW_H*3/8);
    sc->setFont(titleFont);
    levelscene->addItem(sc);

    ///draw the time it took
    QGraphicsTextItem* time = new QGraphicsTextItem(QString("Deine Zeit: "));
    time->setPos(WINDOW_W*4/8,WINDOW_H*3/8);
    time->setFont(titleFont);
    levelscene->addItem(time);

    ///create an add button
    Button* add = new Button(QString("Hinzufügen"));
    connect(add,SIGNAL(clicked()),this,SLOT(CopyInDatei()));
    add->setPos(input->x()+input->width(),input->y());
    levelscene->addItem(add);

}

bool Level::StopCheck()
{
    /**
      * if the ball isn't attached to the spring get the current y-Position of the ball
      * if the level hasn't been paused and the current y-Position is the same as the last time the method was called
      * increase the failing condition variable
      * if the variable exceeds 1500
      * the game is lost
      */
    if (! dynamic_cast<Feder*>(feder->item)->getBallAttached()) {
        int y_current = dynamic_cast<Ball*>(ball->item)->y();
        if( y_current == y_last && isPaused == false) {
            if (failbedingung <= ABBRUCHZEIT) {
                failbedingung++;
            } else {
                levelscene->clear();

                ///draw the losing text
                QGraphicsTextItem* losttext = new QGraphicsTextItem(QString("Sie haben leider verloren"));
                QFont titleFont("comic sans",50);
                losttext->setFont(titleFont);
                int txPos = this->width()/2 - losttext->boundingRect().width()/2;
                int tyPos = WINDOW_H/8;
                losttext->setPos(txPos,tyPos);
                levelscene->addItem(losttext);

                ///create a button to get back to the level menu
                Button* zurueck = new Button(QString("Zurück zur Levelübersicht"));
                connect(zurueck, SIGNAL(clicked()),this,SLOT(Zurueck()));
                zurueck->setRect(0,0,300,50);
                zurueck->setPos(losttext->x()+losttext->boundingRect().width()/3,WINDOW_H*3/8);
                levelscene->addItem(zurueck);

                ///create a button to restart the level
                Button* redo = new Button(QString("Den Level erneut starten"));
                connect(redo, SIGNAL(clicked()),this,SLOT(Redo()));
                redo->setRect(0,0,300,50);
                redo->setPos(losttext->x()+losttext->boundingRect().width()/3, WINDOW_H*4/8);
                levelscene->addItem(redo);

                ///create a button to get back to the main menu
                Button* haupt = new Button(QString("Zum Hauptmenü"));
                connect(haupt, SIGNAL(clicked()),this,SLOT(Hauptmenu()));
                haupt->setRect(0,0,300,50);
                haupt->setPos(losttext->x()+losttext->boundingRect().width()/3, WINDOW_H*5/8);
                levelscene->addItem(haupt);
                timer->stop();
                return true;

            }
        } else {
            failbedingung = 0;
        }
        y_last = y_current;
    } else {
        failbedingung = 0;
        return false;
    }
    return false;
}


/**
 * @brief Level::applyFoehnForces iterates over all foehne, checks whether the ball is in reach of them
 * and applies a force in direction of the foehn if necessary depending on the positions wrt each others
 */
void Level::applyFoehnForces() {
    //iterate over all foehne
    for (int i = 0; i < foehne.size(); i++) {
        //check whether the currently investigated foehn is currently turned on
        if(dynamic_cast<Foehn*>(foehne.at(i)->item)->isOn()) {
            //vector pointing from the tip of the foehn to the center of the ball
            //remember, that points of ball and foehn are located at top-left corner of object
            qDebug() << foehne.at(0)->item->rotation();
            foehnBall = b2Vec2((ball->item->x()+BALL_DIAM/2) - (foehne.at(i)->item->x()+FOEHN_WIDTH/2*(1+sin(foehne.at(i)->item->rotation() * M_PI/180))),
                               (ball->item->y()+BALL_DIAM/2) - (foehne.at(i)->item->y()+FOEHN_WIDTH/2*(1-cos(foehne.at(i)->item->rotation() * M_PI/180))));
            //vector product of direction of foehn and vector from tip of foehn to ball
            //i.e. projection of one vector onto the other thus offset in direction of foehn
            distanceFoehnBall = foehnBall.x*sin(foehne.at(i)->item->rotation() * M_PI/180) -
                                    foehnBall.y*cos(foehne.at(i)->item->rotation() * M_PI/180);
            //computing angle (rads) between both vectors via vector product theorem vec_a*vec_b = |a|*|b|*cos(alpha)
            //as direction vector of foehn is normalized, it has length 1 thus does not need to be considered
            angleFoehnBall = acos(distanceFoehnBall/foehnBall.Length());
            //only applying force if the ball is distance-wise and angle-wise in the reach of the foehn
            //lower bound of angle does not need to be checked as acos only returns poisitive values in between 0 and 90 degrees
                //and for higher angles the distance would be negative
            if (distanceFoehnBall > 0 && distanceFoehnBall < FOEHN_REACH &&
                    angleFoehnBall < FOEHN_REACH_ANGLE) {
                //the intensity of the foehn depends on
                    //1. the angle between the direction of the foehn and the vector from foehn to ball (cos function zero at FOEHN_REACH_ANGLE)
                    //2. the distance of the ball to the foehn in direction of the foehn (inverse)
                intensityFoehn = FOEHN_FORCE * cos(angleFoehnBall * M_PI/(2*FOEHN_REACH_ANGLE)) * FOEHN_REACH/distanceFoehnBall;
                ball->body->ApplyForceToCenter(b2Vec2(intensityFoehn*sin(foehne.at(i)->item->rotation() * M_PI/180),
                                                      intensityFoehn*cos(foehne.at(i)->item->rotation() * M_PI/180)),
                                               true);
            }
        }
    }
}

/**
 * @brief Level::updateB2Balken as the balken class only handles their Qt appearance/position,
 * their box2d position needs to be updated as well. Therefore this method iterates over all balken
 * stored in the QVector of the level and updates their position if the internal modified flag
 * has been set in the respective Qt-item.
 */
void Level::updateB2Balken() {
    //iterate over all balken
    for (int i = 0; i < balken.size(); i++) {
        currentBalken = balken.at(i);
        currentBalkenItem = dynamic_cast<Balken*>(currentBalken->item);
        //nur nicht-statische Balken updaten
        if(currentBalkenItem->getType() != Balken::statisch && currentBalkenItem->wasModified() != Balken::NONE) {
            if(currentBalkenItem->getType() == Balken::translatorisch) {
                //modify the position according to the angle for translational Balken
                if(currentBalkenItem->wasModified() == Balken::LEFT) {
                    currentBalken->body->SetTransform( b2Vec2(currentBalken->body->GetPosition().x - 15*cos(currentBalkenItem->getRotation() * M_PI/180),
                                                             currentBalken->body->GetPosition().y + 15*sin(currentBalkenItem->getRotation() * M_PI/180) ),
                                                       - currentBalkenItem->getRotation() * M_PI/180);
                } else {
                    currentBalken->body->SetTransform( b2Vec2(currentBalken->body->GetPosition().x + 15*cos(currentBalkenItem->getRotation() * M_PI/180),
                                                             currentBalken->body->GetPosition().y - 15*sin(currentBalkenItem->getRotation() * M_PI/180) ),
                                                       - currentBalkenItem->getRotation() * M_PI/180);
                }//left-right differentiation
            } else if (currentBalkenItem->getType() == Balken::rotatorisch) {
                //modify the rotation for rotational Balken (Attention box2d: ccw, Qt: cw)
                if(currentBalkenItem->wasModified() == Balken::LEFT) {
                    currentBalken->body->SetTransform( b2Vec2(currentBalken->body->GetPosition().x,
                                                             currentBalken->body->GetPosition().y ),
                                                       - currentBalkenItem->getRotation() * M_PI/180);
                } else {
                    currentBalken->body->SetTransform( b2Vec2(currentBalken->body->GetPosition().x,
                                                             currentBalken->body->GetPosition().y),
                                                       - currentBalkenItem->getRotation() * M_PI/180);
                }//left-right differentiation
            }//translation-rotation differentiation
            currentBalkenItem->unmodified();
        }//only move non-stationary modified Balken
    }//iterate over all Balken in the level
}
