#ifndef COUNTER_H
    #define COUNTER_H
    #include <QGraphicsTextItem>
    #include <QFont>


    class counter: public QGraphicsTextItem
    {
    public:
     counter();
     void increase();
     int getscore();
     int m_score;
    };

    #endif // COUNTER_H

