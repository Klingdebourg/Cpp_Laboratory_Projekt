#ifndef FEDER_H
#define FEDER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

#include <math.h>

#define WINDOW_W 1600
#define WINDOW_H 1200
#define FEDER_WIDTH 20
#define FEDER_HEIGHT 100

class Feder : public QGraphicsRectItem {
public:
    Feder(int x, int y);
    void keyPressEvent(QKeyEvent *event);
private:
    int spannung;
    //could be used lateron to indicate if the Feder is attached to a Balken and should move together with it
    //bool attachedToBalken
};

#endif // FEDER_H
