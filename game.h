#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include "button.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level.h"
#include "feder.h"
#include "balken.h"

class level1;
class level2;
class level3;
class Level;

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent = NULL);

    QGraphicsScene* scene;

public slots:
    void levelmenu();
    void displayMainMenu();
    void start();

};

#endif // GAME_H
