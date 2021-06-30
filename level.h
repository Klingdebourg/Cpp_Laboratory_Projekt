#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "game.h"
#include "counter.h"
#include "maske.h"
#include "ball.h"
#include "virus.h"
#include "feder.h"
#include "foehn.h"
#include <QGraphicsLineItem>
#include <QList>
#include "definitions.h"
#include "element.h"
#include "info.h"


class Level : public QGraphicsView
{
    Q_OBJECT
public:
    Level(Game* game, int type, QWidget* parent = NULL);
    QGraphicsScene* levelscene;
    Game* levelgame;
    int level;
    b2BodyDef groundBodyDefTop;
    b2BodyDef groundBodyDefBotton;
    b2BodyDef groundBodyDefLeft;
    b2BodyDef groundBodyDefRight;
    QString text;
    QGraphicsScene* pausemenu;
    QGraphicsView* pausepic;
    counter* Counter;
    QTimer* timer;
    int failbedingung;
    int x_last;
    int y_last;
    info* Info;
    QGraphicsRectItem* bounds;
    int finalscore;
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
    bool StopCheck();
    //Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus

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
