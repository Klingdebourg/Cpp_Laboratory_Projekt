#include "counter.h"
#include "game.h"

counter::counter(){
    ///initialize m_score
    m_score = 0;
    ///draw the text
    setPlainText(QString("Score: ")+QString::number(m_score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void counter::increase(){
    ///increase the score and update the text
    m_score += 1;
    setPlainText((QString("Score: ")+QString::number(m_score)));
}

int counter::getscore(){
    ///give back the score
    return m_score;
}
