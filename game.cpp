#include "game.h"

#include <QDebug>
#include <QIcon>
#include "button.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "definitions.h"



Game::Game(QWidget* parent): QGraphicsView(parent){

    /// create the scene
    scene = new QGraphicsScene();

    /** make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    * it can be used to visualize scenes)
    */

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_W,WINDOW_H);
    scene->setSceneRect(0,0,WINDOW_W,WINDOW_H);

    setWindowIcon(QIcon(":/pictures/media/virus.png"));

}

void Game::displayMainMenu(){
    /// create the title text
    scene->clear();
    QPixmap background(":/pictures/media/background1.jpg");
    scene->setBackgroundBrush(background.scaled(WINDOW_W,WINDOW_H,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Get the virus"));
    QFont titleFont("Fantasy",50);
    titleFont.setStyleHint(QFont::Fantasy);
    titleText->setDefaultTextColor(Qt::red);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    /// create the play button
    Button* playButton = new Button(QString("Zu den Levels"));
    connect(playButton,SIGNAL(clicked()),this,SLOT(levelmenu()));
    int pxPos = txPos;
    int pyPos = 600;
    playButton->setPos(pxPos,pyPos);
    scene->addItem(playButton);

    /// create the quit button
    Button* quitButton = new Button(QString("Spiel verlassen"));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    int qxPos = txPos + (titleText->boundingRect().width()/4)*3;
    int qyPos = 600;
    quitButton->setPos(qxPos,qyPos);
    scene->addItem(quitButton);

    ///create the button leading to the game information
    Button* info = new Button(QString("Spielinformationen"));
    connect(info,SIGNAL(clicked()),this,SLOT(Info()));
    int ixPos = txPos;
    int iyPos = 800;
    info->setPos(ixPos,iyPos);
    scene->addItem(info);

    ///create the button leading to the highscores
    Button* scores = new Button(QString("Die Bestenliste"));
    connect(scores,SIGNAL(clicked()),this,SLOT(scores()));
    int sxPos=txPos + (titleText->boundingRect().width()/4)*3;
    int syPos=800;
    scores->setPos(sxPos,syPos);
    scene->addItem(scores);
}
void Game::levelmenu(){
    scene->clear();
    ///draw the title
    QGraphicsTextItem* levelText = new QGraphicsTextItem(QString("Levels"));
    QFont levelFont("Fantasy",50);
    levelFont.setStyleHint(QFont::Fantasy);
    levelText->setDefaultTextColor(Qt::red);
    levelText->setFont(levelFont);
    int lvposx = this->width()/2-levelText->boundingRect().width()/2;
    int lvposy = 200;
    levelText->setPos(lvposx,lvposy);
    scene->addItem(levelText);

    /// create the button for Level 1
    Button* level1 = new Button(QString("1"));
    connect(level1,SIGNAL(clicked()),this,SLOT(start()));
    int l1x = WINDOW_W*3/16;
    int l1y = 500;
    level1->setPos(l1x,l1y);
    scene->addItem(level1);

    /// create the button for Level 2
    Button* level2 = new Button(QString("2"));
    connect(level2,SIGNAL(clicked()),this,SLOT(start()));
    int l2x = WINDOW_W*7/16;
    int l2y = 500;
    level2->setPos(l2x,l2y);
    scene->addItem(level2);

    /// create the button for Level 3
    Button* level3 = new Button(QString("3"));
    connect(level3,SIGNAL(clicked()),this,SLOT(start()));
    int l3x = WINDOW_W*11/16;
    int l3y = 500;
    level3->setPos(l3x,l3y);
    scene->addItem(level3);

    ///create a button to return to the previous menu
    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

}
void Game::start(){
    ///find out which button was clicked
    Button *clickedButton = qobject_cast<Button *>(sender());
    /// depending what button was clicked, create the level
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

    ///draw the title
    QGraphicsTextItem* informationtitle = new QGraphicsTextItem;
    informationtitle->setPlainText(QString("Spielinformationen"));
    QFont titleFont("comic sans",50);
    titleFont.setStyleHint(QFont::Fantasy);
    informationtitle->setFont(titleFont);
    informationtitle->setDefaultTextColor(Qt::red);
    int txPos = this->width()/2 - informationtitle->boundingRect().width()/2;
    int tyPos = 150;
    informationtitle->setPos(txPos,tyPos);
    scene->addItem(informationtitle);

    ///draw the text
    QGraphicsTextItem* information = new QGraphicsTextItem;
    information->setDefaultTextColor(Qt::white);
    information->setPlainText(QString("Das Ziel des Spieles ist es den Virus (roter Ball) mit dem Antikörper-Ball (grüner Ball) zu treffen. Der Ball ist nur bewegbar indem man ihn mit einer Feder abschießt. Die Feder ist schwarz und man kann sie spannen indem man zuerst mit der Maus auf sie drückt und dann mit den Pfeiltasten \"Auf\" und \"Ab\" die Spannhöhe angibt. Mit den Pfeiltasten \"Rechts\" und \"Links\" lässt sich die Feder ausrichten. Zum Abschießen drückt man die Leertaste. Während des Spieles kann man Masken einsammeln (Gelbe Quadrate), hierbei erhöht sich der Score. Es gibt drei verschiedene Arten von Balken an dem der Antikörper-Ball abprallt. Die schwarzen Balken sind starr, die hellblauen Balken sind rotatorisch. Mit den Pfeiltasten \"Rechts\" und \"Links\" lässt sich die Rotation einstellen. Die hellgrünen Balken sind translatorisch, sie lassen sich ebenfalls mit den Pfeiltasten nach links und rechts bewegen."));
    information->setPos(informationtitle->x()+informationtitle->boundingRect().width()*1/16,informationtitle->y()+200);
    QFont textFont("times",10);
    textFont.setStyleHint(QFont::Courier);
    information->setFont(textFont);
    information->adjustSize();
    scene->addItem(information);

    ///create a return button to get back to the previous menu
    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

}


void Game::scores()
{
    scene->clear();

    ///draw the text to get to the highscores
    QGraphicsTextItem* scoreText = new QGraphicsTextItem(QString("Die Bestenliste der Level:"));
    scoreText->setDefaultTextColor(Qt::red);
    QFont levelFont("times",50);
    scoreText->setFont(levelFont);
    int lvposx = this->width()/2-scoreText->boundingRect().width()/2;
    int lvposy = 200;
    scoreText->setPos(lvposx,lvposy);
    scene->addItem(scoreText);

    /// create the button for Level 1
    Button* level1 = new Button(QString("1"));
    connect(level1,SIGNAL(clicked()),this,SLOT(best()));
    int l1x = WINDOW_W*3/16;
    int l1y = 500;
    level1->setPos(l1x,l1y);
    scene->addItem(level1);

    /// create the button for Level 2
    Button* level2 = new Button(QString("2"));
    connect(level2,SIGNAL(clicked()),this,SLOT(best()));
    int l2x = WINDOW_W*7/16;
    int l2y = 500;
    level2->setPos(l2x,l2y);
    scene->addItem(level2);

    /// create the button for Level 3
    Button* level3 = new Button(QString("3"));
    connect(level3,SIGNAL(clicked()),this,SLOT(best()));
    int l3x = WINDOW_W*11/16;
    int l3y = 500;
    level3->setPos(l3x,l3y);
    scene->addItem(level3);

    ///create a return button to get back to the main menu
    Button* back = new Button(QString("<-"));
    connect(back, SIGNAL(clicked()),this,SLOT(displayMainMenu()));
    scene->addItem(back);

}

void Game::best()
{
    scene->clear();

}
