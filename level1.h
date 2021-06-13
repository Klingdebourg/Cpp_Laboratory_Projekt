#ifndef LEVEL1_H
#define LEVEL1_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "balken.h"
#include "virus.h"
#include "maske.h"
#include "feder.h"
#include "counter.h"
#include <QGraphicsLineItem>
#include "button.h"
#include "game.h"

class Game;

class Level1: public QGraphicsView
{
    Q_OBJECT
public:
    Level1(Game* game, QWidget* parent = NULL);
    QGraphicsScene* scene1;
public slots:
    void pause();
    void Zurueck();
    void Redo();
};

#endif // LEVEL1_H
