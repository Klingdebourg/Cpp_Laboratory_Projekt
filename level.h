#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "game.h"
#include <QGraphicsLineItem>



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
