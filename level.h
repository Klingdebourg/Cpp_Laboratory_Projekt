#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "game.h"
#include "counter.h"
#include "maske.h"
#include "ball.h"
#include "virus.h"
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QList>
#include "definitions.h"
#include <box2d.h>


class Level : public QGraphicsView
{
    Q_OBJECT
public:
    Level(Game* game, int type, QWidget* parent = NULL);
    Game* levelgame;
    b2World *world;
    float timeStep;
    int velocityIterations;
    int positionIterations;

    int level;
    QString text;
    QGraphicsScene* levelscene;
    QGraphicsScene* pausemenu;
    QGraphicsView* pausepic;
    counter* Counter;
    Ball* ball;
    b2BodyDef* bodyDefBall;
    b2Body *bodyBall;
    b2FixtureDef *fixtureBall;
    b2CircleShape *circle;
    Maske* maske1;
    Maske* maske2;
    Maske* maske3;
    Virus* virus;
public slots:
    void pause();
    void Zurueck();
    void Redo();
    void Hauptmenu();
    void Interaktion();
//    Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus
};

#endif // LEVEL_H
