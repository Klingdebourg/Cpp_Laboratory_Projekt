#include "feder.h"

Feder::Feder(int x, int y) : {
    int x_, y_;
    if (x < 0)
        x_ = 0;
    else if (x > WINDOW_W)
        x_ = WINDOW_W;
    else {
        x_ = x;
    }
    if (y < 0)
        y_ = 0;
    else if (y > WINDOW_H)
        y_ = WINDOW_H;
    else {
        y_ = y;
    }
    setRect(x_, y_, FEDER_WIDTH, FEDER_HEIGHT);
}
