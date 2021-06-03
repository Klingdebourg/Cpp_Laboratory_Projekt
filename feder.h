#ifndef FEDER_H
#define FEDER_H

#include "QGraphicsRectItem"

#define WINDOW_W 1600
#define WINDOW_H 1200
#define FEDER_WIDTH 20
#define FEDER_HEIGHT 100

class Feder : public QGraphicsRectItem {
public:
    Feder(int x, int y);
private:
    int spannung;
};

#endif // FEDER_H
