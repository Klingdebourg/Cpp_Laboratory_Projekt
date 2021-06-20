#ifndef MASKE_H
#define MASKE_H

#include <QGraphicsRectItem>
#include <QRectF>

class Maske : public QGraphicsRectItem {
public:
    Maske(int x, int y, QRectF *a=0);
}

#endif // MASKE_H
