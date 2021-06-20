#include "maske.h"
#include <QRectF>
#include "definitions.h"

Maske::Maske(int x, int y, QRectF *a)

{
    setRect(x, y, MASKE_BREITE, MASKE_BREITE);
}
