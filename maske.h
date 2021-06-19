#ifndef MASKE_H
#define MASKE_H

#include <QGraphicsRectItem>
#include <QRectF>

#define MASKE_BREITE 80

class Maske : public QGraphicsRectItem {
public:
    Maske(int x, int y, QRectF *a=0);
    int maskencounter = 0;
};

#endif // MASKE_H
