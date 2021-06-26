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
    Game* levelgame;
    int level;
    b2World *world;
    QString text;
    QGraphicsScene* levelscene;
    QGraphicsScene* pausemenu;
    QGraphicsView* pausepic;
    counter* Counter;
    Element* ball;
    b2Vec2 ballStep;
    Element* maske1;
    Element* maske2;
    Element* maske3;
    Element* virus;
    Element* feder;
    QTimer* timer;
    int failbedingung;
    int x_last;
    int y_last;
    int x_current;
    int y_current;
    info* Info;
    QGraphicsRectItem* bounds;
public slots:
    void pause();
    void Zurueck();
    void Redo();
    void Hauptmenu();
    void Interaktion();
    void InfoToBeClosed();
    //Maske* maske1, Maske* maske2, Maske* maske3, Virus* virus

private:
    bool isPaused;
};

#endif // LEVEL_H
