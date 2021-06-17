#ifndef LEVEL3_H
#define LEVEL3_H

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
class Level;

class Level3: public QGraphicsView
{
    Q_OBJECT
public:
    Level3(Game* game, QWidget* parent = NULL);
    QGraphicsScene* scene3;
public slots:
    void pause();
    void Zurueck();
    void Redo();
};

#endif // LEVEL3_H
