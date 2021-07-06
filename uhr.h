#ifndef UHR_H
#define UHR_H

#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>

class Uhr: public QGraphicsTextItem{
public:
    Uhr();
    QTime time;
    int t_elapsed = 0;
    unsigned int m = 0;
    unsigned int s = 0;
    unsigned int ms = 0;
    QString m_str;
    QString s_str;
    QString ms_str;
    QString elapsed_str;

public slots:
    void start();
    void time_elapsed();
    QString gettime();
};



#endif // UHR_H
