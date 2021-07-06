#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QInputDialog>
#include "game.h"
#include "counter.h"
#include "maske.h"
#include "ball.h"
#include "virus.h"
#include "feder.h"
//#include "balken.h"
#include "foehn.h"
#include <QGraphicsLineItem>
#include <QList>
#include "definitions.h"
#include "element.h"
#include "info.h"
#include "uhr.h"
#include "highscore.h"


class Level : public QGraphicsView
{
    Q_OBJECT
public:
    Level(Game* game, int type, QWidget* parent = NULL);
    Game* levelgame;
    int level;
    b2BodyDef groundBodyDefTop;
    b2BodyDef groundBodyDefBotton;
    b2BodyDef groundBodyDefLeft;
    b2BodyDef groundBodyDefRight;
    QString text;
    QGraphicsScene* levelscene;
    QGraphicsScene* pausemenu;
    QGraphicsView* pausepic;
    counter* Counter;
    QTimer* timer;
    Uhr* uhr;
    Highscore* newHighscore;
    int failbedingung;
    int x_last;
    int y_last;
    int x_current;
    int y_current;
    info* Info;
    QGraphicsRectItem* bounds;
    int finalscore;
    QString finaltime;
    QLineEdit* input;
public slots:
    void pause();
    void Zurueck();
    void Redo();
    void Hauptmenu();
    void Interaktion();
    void InfoToBeClosed();
    void Gewonnen();
    void Next();
    void AddScore();
    void insertScore();
    void showHighscore(int level);
    bool StopCheck();
protected:
    b2World *world;
    Element* ball;
    b2Vec2 ballStep;
    Element* feder;
    Element* maske1;
    Element* maske2;
    Element* maske3;
    Element* virus;
    QVector<Element*> balken;
    QVector<Element*> foehne;
    QString Spielername;
private:
    Element* currentBalken;
    Balken* currentBalkenItem;
    b2Vec2 foehnBall;
    int distanceFoehnBall;
    float angleFoehnBall;
    float intensityFoehn;
    bool isPaused;

    void applyFoehnForces();
    void updateB2Balken();
};

#endif // LEVEL_H
