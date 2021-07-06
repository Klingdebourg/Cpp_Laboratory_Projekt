#include "game.h"

#include <QDebug>
#include "button.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "definitions.h"



Game::Game(QWidget* parent): QGraphicsView(parent){

    // create the scene
    scene = new QGraphicsScene();

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_W,WINDOW_H);
    scene->setSceneRect(0,0,WINDOW_W,WINDOW_H);

    informationtitle = new QGraphicsTextItem;
    information = new QGraphicsTextItem;
    newHighscore = new Highscore();
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


    Button* info = new Button(QString("Spielinformationen"));
    connect(info,SIGNAL(clicked()),this,SLOT(Info()));
    int ixPos = txPos;
    int iyPos = 800;
    info->setPos(ixPos,iyPos);
    scene->addItem(info);


    Button* scores = new Button(QString("Die Bestenliste"));
      connect(scores,SIGNAL(clicked()),this,SLOT(scores()));
      int sxPos=txPos + (titleText->boundingRect().width()/4)*3;
      int syPos=800;
      scores->setPos(sxPos,syPos);
      scene->addItem(scores);
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

    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

}
void Game::start(){
    Button *clickedButton = qobject_cast<Button *>(sender());
    if (clickedButton->gettext() == "1"){
        Level1 *level1 = new Level1(this);
        level1->show();
        this->hide();
    } else if (clickedButton->gettext() == "2") {
        Level2 *level2 = new Level2(this);
        level2->show();
        this->hide();
    } else {
        Level3 *level3= new Level3(this);
        level3->show();
        this->hide();
    }
}

void Game::Info()
{
    scene->clear();

    //Informationen wie man das Spiel spielt werden hier hereingeschrieben

    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

    informationtitle->setPlainText(QString("Spielinformationen"));
    QFont titleFont("comic sans",50);
    informationtitle->setFont(titleFont);
    int txPos = this->width()/2 - informationtitle->boundingRect().width()/2;
    int tyPos = 150;
    informationtitle->setPos(txPos,tyPos);
    scene->addItem(informationtitle);

    information->setPlainText(QString("Das Ziel des Spieles ist es den Virus (roter Ball) mit dem Antikörper-Ball (grüner Ball) zu treffen. Der Ball ist bewegbar nur in dem man ihn mit einer Feder abschießt. Die Feder ist schwarz und man kann sie spannen indem man zuerst mit der Maus auf sie drückt und dann mit den Pfeiltasten auf und ab die Spannhöhe angibt. Mit den Pfeiltasten rechts und links lässt sich die Feder ausrichten. ZUm Abschießen drückt man die Leertaste. Während des Spieles kann man Masken einsammeln (Gelbe Quadrate), hierbei erhöht sich der Score. Es gibt drei verschiedene Arten von Balken an dem der Antikörper-Ball abprallt. Die schwarzen Balken sind starr, die hellgrünen Balken sind rotatorisch. Mit den Pfeiltasten rechts und links lässt sich die Rotation einstellen. Die hellblauen Balken sind translatorisch, sie lassen sich ebenfalls mit den Pfeiltasten nach links und rechts bewegen."));
    information->setPos(informationtitle->x()+informationtitle->boundingRect().width()*3/16,informationtitle->y()+200);
    QFont textFont("times",10);
    information->setFont(textFont);
    information->adjustSize();
    scene->addItem(information);

}


void Game::scores()
{
    scene->clear();

    QGraphicsTextItem* scoreText = new QGraphicsTextItem(QString("Die Bestenliste der Level:"));
    QFont levelFont("times",50);
    scoreText->setFont(levelFont);
    int lvposx = this->width()/2-scoreText->boundingRect().width()/2;
    int lvposy = 200;
    scoreText->setPos(lvposx,lvposy);
    scene->addItem(scoreText);

    // create the button for Level 1
    Button* level1 = new Button(QString("1"));
    connect(level1,SIGNAL(clicked()),this,SLOT(level1clicked()));
    int l1x = this->width()/2-scoreText->boundingRect().width();
    int l1y = 500;
    level1->setPos(l1x,l1y);
    scene->addItem(level1);

    // create the button for Level 2
    Button* level2 = new Button(QString("2"));
    connect(level2,SIGNAL(clicked()),this,SLOT(level2clicked()));
    int l2x = this->width()/2 - level2->boundingRect().width()/2;
    int l2y = 500;
    level2->setPos(l2x,l2y);
    scene->addItem(level2);

    // create the button for Level 3
    Button* level3 = new Button(QString("3"));
    connect(level3,SIGNAL(clicked()),this,SLOT(level3clicked()));
    int l3x = this->width()/2+scoreText->boundingRect().width()/2;
    int l3y = 500;
    level3->setPos(l3x,l3y);
    scene->addItem(level3);

    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

}

void Game::level1clicked(){
    best(1);
}

void Game::level2clicked(){
    best(2);
}

void Game::level3clicked(){
    best(3);
}

void Game::best(int level){
    scene->clear();

    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(scores()));
    scene->addItem(back);

    QGraphicsTextItem* enternametitle = new QGraphicsTextItem(QString("Highscore Level" + QString::number(level)));
    QFont titleFont("comic sans",30);
    enternametitle->setFont(titleFont);
    enternametitle->setPos(WINDOW_W/16,WINDOW_H/8);
    scene->addItem(enternametitle);

    QString outputText = newHighscore -> read(level);
    QGraphicsTextItem* highscoreOutput = new QGraphicsTextItem(outputText);
    QFont titleFontText("comic sans",20);
    highscoreOutput->setPos(WINDOW_W*1/8,WINDOW_H*2/8);
    highscoreOutput->setFont(titleFontText);
    scene->addItem(highscoreOutput);

}
