#ifndef MASKE_H
#define MASKE_H

#include <QGraphicsRectItem>
#include <QRectF>

#define MASKE_BREITE 80

class maske : public QGraphicsRectItem {
public:
    maske(int x, int y, QRectF *a=0);
    int maskencounter = 0;
};

#endif // MASKE_H
