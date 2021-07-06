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
    int rowsHS1 = 0;
    int rowsHS2 = 0;
    int rowsHS3 = 0;
public slots:
    void write();
    QString read(int level);
    int countRows(QString filename);
    void insertScore(QString Name, QString Zeit, int Masken, int level);
};

#endif // HIGHSCORE_H
