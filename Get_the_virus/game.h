#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent = NULL);

    QGraphicsScene* scene;

    void displayMainMenu();
};

#endif // GAME_H
