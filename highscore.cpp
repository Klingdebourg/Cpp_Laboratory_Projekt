#include "highscore.h"

Highscore::Highscore(){
}

QString Highscore::read(int level){    
    ///defines String to insert the filename for the level
    QString filename;
    ///choses name of the file according the which level was played
    if(level == 1){
        filename = "highscore1.txt";
    } else if(level == 2){
        filename = "highscore2.txt";
    } else if(level == 3){
        filename = "highscore3.txt";
    }
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        return "";
    }
    ///create a new QTextStream and insert file and inserts the text that is in the textfile
    QTextStream in(&file);
    QString line = in.readAll();
    /// returns text of highscorefile so it can be showed in a Highscoreoutput
    return line;
    file.close();
}

void Highscore::insertScore(QString Name, QString Zeit, int Masken, int level){
    ///defines String to insert the filename for the level
    QString filename;
    ///choses name of the file according the which level was played
    if(level == 1){
        filename = "highscore1.txt";
    } else if(level == 2){
        filename = "highscore2.txt";
    } else if(level == 3){
        filename = "highscore3.txt";
    }
    QFile file(filename);
    QFileDevice::Permissions p = file.permissions();
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        return;
    }
    ///line [15] to save the lines that were already in the file
    QString line[15];
    int row = 0;
    ///create a new QTextStream and insert file
    QTextStream out(&file);
    ///create new Highscore Output and add all outputs to the Text stream
    line[row] = Name + ": Zeit: " + Zeit + ", gesammelte Masken: " + QString::number(Masken);
    line[row+1] = out.readAll();
    while(!out.atEnd()){
        out << line[row] << endl;
        row++;
    }
    out << line[row] << endl;
    file.flush();
    file.close();
}
