#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "game.h"
#include <QGraphicsLineItem>
#include "button.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

class Game;
class Level1;
class Level2;
class Level3;

class Level : public QGraphicsView
{
    Q_OBJECT
public:
    Level(Game* game, int type, QWidget* parent = NULL);
    Game* levelgame;
    int level;
    QString text;
    QGraphicsScene* levelscene;
    QGraphicsScene* pausemenu;
    QGraphicsView* pausepic;
public slots:
    void pause();
    void Zurueck();
    void Redo();
};

#endif // LEVEL_H
