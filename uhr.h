#ifndef UHR_H
#define UHR_H

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
    /**
     * @brief starts the timer (e.g. when the ball starts moving)
     */
    void start();
    /**
     * @brief gives back the passed time after the clock was started
     */
    void time_elapsed();
    /**
     * @brief gettime gives back the passed time in a clock format (not in integer time format)
     */
    QString gettime();
};



#endif // UHR_H
