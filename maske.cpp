
#include "maske.h"
#include <QRectF>

Maske::Maske(int x, int y, QRectF *a)
{
    setRect(x, y, MASKE_BREITE, MASKE_BREITE);
}
