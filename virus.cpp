#include "virus.h"
#include <QRectF>

Virus::Virus(int x, int y, QRectF *a)
{
    setRect(x, y, VIRUS_RADIUS, VIRUS_RADIUS);
}
