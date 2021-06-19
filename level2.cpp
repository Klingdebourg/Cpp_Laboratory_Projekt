#include "level2.h"
#include <QDebug>
#include "virus.h"
#include "foehn.h"

Level2::Level2()
{
    qDebug() << "Level 2 erstellt.";
    game -> scene -> clear();
    Virus *virus1 = new Virus(100, 100);
    game -> scene -> addItem(virus1);
    Foehn * foehn1 = new Foehn (100,100);
    game -> scene -> addItem(foehn1);
}
