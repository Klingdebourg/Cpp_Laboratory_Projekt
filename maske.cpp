#include "maske.h"
#include <QRectF>

maske::maske(int x, int y, QRectF *a)
{
    setRect(x, y, MASKE_BREITE, MASKE_BREITE);
}
