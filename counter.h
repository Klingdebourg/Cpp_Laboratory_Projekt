#ifndef COUNTER_H
    #define COUNTER_H
    #include <QGraphicsTextItem>
    #include <QFont>


    class counter: public QGraphicsTextItem
    {
    public:
        /**
      * @brief counter constructor
      *
      * Counter is a class that is active in every level counting up the collected masks
      */
     counter();
     /**
      * @brief increase increases the private variable m_score and actualizes the GUI, when called (mask is collected)
      */
     void increase();
     /**
      * @brief getscore gives back the private variable m_score
      * @return returns the score of the collected masks
      */
     int getscore();
    private:
     /**
      * @brief m_score private variable that saves the number of collected masks
      */
     int m_score;
    };

    #endif // COUNTER_H

