#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include "button.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include <QDebug>


#define WINDOW_W 1600
#define WINDOW_H 1200

Game::Game(QWidget* parent){

    // create the scene
    scene = new QGraphicsScene();

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)

    setScene(scene);
    show();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_W,WINDOW_H);
    scene->setSceneRect(0,0,WINDOW_W,WINDOW_H);
}

void Game::displayMainMenu(){
    // create the title text
    scene->clear();
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Get the virus"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Zu den Levels"));
    connect(playButton,SIGNAL(clicked()),this,SLOT(levelmenu()));
    int pxPos = txPos;
    int pyPos = 600;
    playButton->setPos(pxPos,pyPos);
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Spiel verlassen"));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    int qxPos = txPos + (titleText->boundingRect().width()/4)*3;
    int qyPos = 600;
    quitButton->setPos(qxPos,qyPos);
    scene->addItem(quitButton);
}
void Game::levelmenu(){
    scene->clear();

    QGraphicsTextItem* levelText = new QGraphicsTextItem(QString("Levels"));
    QFont levelFont("times",50);
    levelText->setFont(levelFont);
    int lvposx = this->width()/2-levelText->boundingRect().width()/2;
    int lvposy = 200;
    levelText->setPos(lvposx,lvposy);
    scene->addItem(levelText);

    // create the button for Level 1
    Button* level1 = new Button(QString("1"));
    connect(level1,SIGNAL(clicked()),this,SLOT(start()));
    int l1x = this->width()/2-levelText->boundingRect().width();
    int l1y = 500;
    level1->setPos(l1x,l1y);
    scene->addItem(level1);

    // create the button for Level 2
    Button* level2 = new Button(QString("2"));
    connect(level2,SIGNAL(clicked()),this,SLOT(start()));
    int l2x = this->width()/2 - level2->boundingRect().width()/2;
    int l2y = 500;
    level2->setPos(l2x,l2y);
    scene->addItem(level2);

    // create the button for Level 3
    Button* level3 = new Button(QString("3"));
    connect(level3,SIGNAL(clicked()),this,SLOT(start()));
    int l3x = this->width()/2+levelText->boundingRect().width()/2;
    int l3y = 500;
    level3->setPos(l3x,l3y);
    scene->addItem(level3);

    Button* back = new Button(QString("<-"),0);
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

}
void Game::start(){
    Button *clickedButton = qobject_cast<Button *>(sender());
    clickedButton->gettext();
    if (clickedButton->gettext() == "1"){
        Level1 *level1 = new Level1;
    }else{
        if (clickedButton->gettext() == "2"){
            Level2 *level2 = new Level2;
        }
        else{
            Level3 *level3 = new Level3;
        }
    }
}
