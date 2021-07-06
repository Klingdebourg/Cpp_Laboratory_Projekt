#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include "highscore.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent = NULL);

    QGraphicsScene* scene;

    QGraphicsTextItem* informationtitle;
    QGraphicsTextItem* information;
    Highscore* newHighscore;

public slots:
    void levelmenu();
    void displayMainMenu();
    void start();
    void Info();
    void scores();
    void best(int level);
    void level1clicked();
    void level2clicked();
    void level3clicked();
};

#endif // GAME_H
