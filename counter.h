#ifndef COUNTER_H
    #define COUNTER_H
    #include <QGraphicsTextItem>
    #include <QFont>


    class counter: public QGraphicsTextItem
    {
    public:
     ///
     /// \brief counter Konstruktor für einen Counter
     ///
     /// Der Counter ist pro Level aktiv und trackt die gesammelten Masken. Der Score wird dabei am Bildschirm ausgegeben
     ///
     counter();
     ///
     /// \brief increase Setzt die private Variable m_score bei Aufruf nach oben und aktualisiert die Ausgabe auf den Bildschirm
     ///
     void increase();
     ///
     /// \brief getscore Gibt den Score, beziehungsweise die private Variable m_score zurück
     /// \return
     ///
     int getscore();
    private:
     ///
     /// \brief m_score Die private Variable die die Anzahl der gesammelten Masken in sich speichert
     ///
     int m_score;
    };

    #endif // COUNTER_H

