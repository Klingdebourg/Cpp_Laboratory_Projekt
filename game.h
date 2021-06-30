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
    /**
     * @brief Game constructor
     * @param parent to be given to the parent class
     *
     * Game inherits from QGraphicsView to manage what should be seen
     */
    Game(QWidget* parent = NULL);


public slots:
    /**
     * @brief levelmenu displays a menu where the player can choose the level
     */
    void levelmenu();
    /**
     * @brief displayMainMenu displays the main menu that the player sees when he opens the game
     */
    void displayMainMenu();
    /**
     * @brief start method that calls upon the level that should be played
     */
    void start();
    /**
     * @brief Info is being called when the player wants to know about the games info
     */
    void Info();
    /**
     * @brief scores is being called when the player wants to know the scores that were saved previously
     */
    void scores();
    /**
     * @brief best is being called when the player selected a level from which they want to kno the scores
     */
    void best();
private:
    /**
     * @brief scene object of the type QGraphicsScene to add object to the scene or in general manage the GUI
     */
    QGraphicsScene* scene;



};

#endif // GAME_H
