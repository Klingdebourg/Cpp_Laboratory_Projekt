#include "highscore.h"

Highscore::Highscore(){
}

void Highscore::write(){
    QFile file1("highscore1.txt");
    if (!file1.open(QFile::WriteOnly | QFile::Text)) {
        return;
    }
    QTextStream out1(&file1);
    QString line1 = "Hello";
    out1 << line1;
    file1.flush();
    file1.close();
}

QString Highscore::read(int level){
    QString filename;
    if(level == 1){
        filename = "C:/Users/paula/Documents/TUM/Bachelor/6.Semester/Cpp/Hauptprojekt/Spiel/gruppe-3-hauptprojekt/highscores/highscore1.txt";
    } else if(level == 2){
        filename = "C:/Users/paula/Documents/TUM/Bachelor/6.Semester/Cpp/Hauptprojekt/Spiel/gruppe-3-hauptprojekt/highscores/highscore2.txt";
    } else if(level == 3){
        filename = "C:/Users/paula/Documents/TUM/Bachelor/6.Semester/Cpp/Hauptprojekt/Spiel/gruppe-3-hauptprojekt/highscores/highscore3.txt";
    }
    QFile file(filename);    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return "";
    }
    QTextStream in(&file);
    QString line = in.readAll();
    return line;
    file.close();
}

void Highscore::insertScore(QString Name, QString Zeit, int Masken, int level){
    QString filename;
    if(level == 1){
        filename = "C:/Users/paula/Documents/TUM/Bachelor/6.Semester/Cpp/Hauptprojekt/Spiel/gruppe-3-hauptprojekt/highscores/highscore1.txt";
    } else if(level == 2){
        filename = "C:/Users/paula/Documents/TUM/Bachelor/6.Semester/Cpp/Hauptprojekt/Spiel/gruppe-3-hauptprojekt/highscores/highscore2.txt";
    } else if(level == 3){
        filename = "C:/Users/paula/Documents/TUM/Bachelor/6.Semester/Cpp/Hauptprojekt/Spiel/gruppe-3-hauptprojekt/highscores/highscore3.txt";
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        return;
    }
    QString line[15];
    int row = 0;
    QTextStream out(&file);
    line[row] = Name + ": Zeit: " + Zeit + ", gesammelte Masken: " + QString::number(Masken);
    line[row + 1]=out.readAll();
    while(!out.atEnd()){
        out << line[row] << endl;
        row++;
    }
    out << line[row] << endl;
    file.close();
}
