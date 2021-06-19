#include "uhr.h"

Uhr::Uhr(QWidget *parent) : QLCDNumber(parent){
    setSegmentStyle(Filled);

    QTimer *Stoppuhr = new QTimer(this);
    connect(Stoppuhr, &QTimer::timeout, this, &Uhr::passedTime);
    Stoppuhr->start(1000);

    passedTime();
}

void Uhr::passedTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
