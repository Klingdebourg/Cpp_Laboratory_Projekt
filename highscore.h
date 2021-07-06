#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QGraphicsTextItem>
#include "definitions.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QDebug>


class Highscore: public QGraphicsTextItem{
public:
    Highscore();
public slots:
    /**
     * @brief when read is being called, the highscore file of the given level is read and returned
     */
    QString read(int level);
    /**
     * @brief adds the new score to the highscore file of the given level
     */
    void insertScore(QString Name, QString Zeit, int Masken, int level);
};

#endif // HIGHSCORE_H
