#ifndef VIRUS_H
#define VIRUS_H

#include "QGraphicsEllipseItem"
#include <QRectF>

class Virus : public QGraphicsEllipseItem {
public:
    Virus(int x, int y, QRectF *a = nullptr);
};

#endif // VIRUS_H
