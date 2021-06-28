#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>




class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent = NULL);

    QGraphicsScene* scene;

    QGraphicsTextItem* informationtitle;
    QGraphicsTextItem* information;

public slots:
    void levelmenu();
    void displayMainMenu();
    void start();
    void Info();
    void scores();
    void best();

};

#endif // GAME_H
