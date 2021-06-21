#include "virus.h"
#include <QRectF>
#include "definitions.h"

Virus::Virus(int x, int y, QRectF *a)
{
    QPixmap pic("media/virus.png");
    setRect(x, y, VIRUS_RADIUS, VIRUS_RADIUS);
}
