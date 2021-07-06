#include "uhr.h"


Uhr::Uhr(){
    time.start();
    setPlainText(QString("Passed Time: 00:00:000"));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Uhr::start(){
    time.restart();
    setPlainText(QString("Passed Time: 00:00:000"));
}

void Uhr::time_elapsed(){
    t_elapsed = time.elapsed();
    m = (t_elapsed / 1000 / 60);
    s = (t_elapsed / 1000) - (m * 60);
    ms = t_elapsed - (s + (m * 60)) * 1000;
    m_str = QString::number(m);
    s_str = QString::number(s);
    ms_str = QString::number(ms);
    elapsed_str = m_str + ":" + s_str + "," + ms_str;
    setPlainText(QString("Passed Time: ") + elapsed_str );
}

QString Uhr::gettime(){
    return elapsed_str;
}


