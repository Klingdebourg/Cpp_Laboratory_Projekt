#ifndef FOEHN_H
#define FOEHN_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>

#define FOEHN_BREITE 100

class Foehn : public QGraphicsRectItem{
public:
    Foehn(int x, int y);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    bool foehn_on = false;
};

#endif // FOEHN_H
