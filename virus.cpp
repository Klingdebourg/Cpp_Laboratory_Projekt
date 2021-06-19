#include "virus.h"
#include <QRectF>

Virus::Virus(int x, int y, QRectF *a)
{
    QPixmap pic("media/virus.png");
    setRect(x, y, VIRUS_RADIUS, VIRUS_RADIUS);
}
