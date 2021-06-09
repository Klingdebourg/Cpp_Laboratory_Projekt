
#ifndef LEVEL2_H
#define LEVEL2_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "balken.h"
#include "virus.h"
#include "maske.h"
#include "feder.h"
#include "counter.h"


class Level2: public QGraphicsView
{
public:
    Level2();
    QGraphicsScene* scene;
};

#endif // LEVEL2_H
