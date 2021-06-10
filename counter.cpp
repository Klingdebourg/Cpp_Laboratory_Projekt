
#include "counter.h"
#include "game.h"

counter::counter()
{
m_score = 0;
setPlainText(QString("Score: ")+QString::number(m_score));
setDefaultTextColor(Qt::green);
setFont(QFont("times",16));
}
void counter::increase(){
m_score ++;
}
int counter::getscore(){
    return m_score;
}
