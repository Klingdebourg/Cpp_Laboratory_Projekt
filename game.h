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
    ///
    /// \brief Game Konstruktor für Game
    /// \param parent Zur Übergabe an das Elternteil QGraphicsView
    ///
    Game(QWidget* parent = NULL);


public slots:
    ///
    /// \brief levelmenu
    ///
    void levelmenu();
    ///
    /// \brief displayMainMenu
    ///
    void displayMainMenu();
    ///
    /// \brief start
    ///
    void start();
    ///
    /// \brief Info
    ///
    void Info();
    ///
    /// \brief scores
    ///
    void scores();
    ///
    /// \brief best
    ///
    void best();
private:
    ///
    /// \brief scene
    ///
    QGraphicsScene* scene;
    ///
    /// \brief informationtitle
    ///
    QGraphicsTextItem* informationtitle;
    ///
    /// \brief information
    ///
    QGraphicsTextItem* information;


};

#endif // GAME_H
