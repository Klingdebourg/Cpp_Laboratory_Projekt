#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include "button.h"

Game::Game(QWidget* parent){

    // create the scene
    scene = new QGraphicsScene();

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)

    setScene(scene);
    show();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600,1200);
    scene->setSceneRect(0,0,1600,1200);
}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Get the virus"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Spielen"));
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    int pxPos = txPos;
    int pyPos = 600;
    playButton->setPos(pxPos,pyPos);
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Verlassen"));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    int qxPos = txPos + titleText->boundingRect().width()/2;
    int qyPos = 600;
    quitButton->setPos(qxPos,qyPos);
    scene->addItem(quitButton);
}
