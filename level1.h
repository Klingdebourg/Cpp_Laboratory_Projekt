#ifndef LEVEL1_H
#define LEVEL1_H

#include "balken.h"
#include "virus.h"
#include "feder.h"
#include "ball.h"

#include <QGraphicsView>
#include <QGraphicsScene>

#include "balken.h"

#define WINDOW_W 1600
#define WINDOW_H 1200


class Level1: public QGraphicsView
{
    Q_OBJECT
public:
    Level1();
    QGraphicsScene* scene;

};

#endif // LEVEL1_H
