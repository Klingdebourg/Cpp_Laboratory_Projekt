
#ifndef LEVEL2_H
#define LEVEL2_H

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

class Level2: public QGraphicsView
{
    Q_OBJECT
public:
    Level2(Game* game, QWidget* parent = NULL);
    QGraphicsScene* scene2;
public slots:
    void pause();
    void Zurueck();
    void Redo();
};

#endif // LEVEL2_H
