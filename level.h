#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QInputDialog>
#include "game.h"
#include "counter.h"
#include "maske.h"
#include "ball.h"
#include "virus.h"
#include "feder.h"
#include "foehn.h"
#include <QGraphicsLineItem>
#include <QList>
#include "definitions.h"
#include "element.h"
#include "info.h"
#include "uhr.h"
#include "highscore.h"


class Level : public QGraphicsView
{
    Q_OBJECT
public:
    Level(Game* game, int type, QWidget* parent = NULL);
    QGraphicsScene* levelscene;
    Game* levelgame;
    int level;
    b2BodyDef groundBodyDefTop;
    b2BodyDef groundBodyDefBottom;
    b2BodyDef groundBodyDefLeft;
    b2BodyDef groundBodyDefRight;
    QString text;
    QGraphicsScene* pausemenu;
    QGraphicsView* pausepic;
    counter* Counter;
    QTimer* timer;
    Uhr* uhr;
    Highscore* newHighscore;
    int failbedingung;
    int x_last;
    int y_last;
    info* Info;
    QGraphicsRectItem* bounds;
    int finalscore;
    QString finaltime;
    QLineEdit* input;
public slots:
    void pause();
    void Zurueck();
    void Redo();
    void Hauptmenu();
    void Interaktion();
    void InfoToBeClosed();
    void Gewonnen();
    void Next();
    void AddScore();
    void insertScore();
    void showHighscore(int level);
protected:
    /**
     * @brief world the world for the box2d engine managing all physics
     */
    b2World *world;
    /**
     * @brief ball the ball moving through the world
     */
    Element* ball;
    /**
     * @brief ballStep a vector containing the movement of the ball in each timestep
     */
    b2Vec2 ballStep;
    /**
     * @brief feder the spring in each level to shoot tha ball
     */
    Element* feder;
    /**
     * @brief maske1 the first item to be collected
     */
    Element* maske1;
    /**
     * @brief maske2 the second item to be collected
     */
    Element* maske2;
    /**
     * @brief maske3 the third item to be collected
     */
    Element* maske3;
    /**
     * @brief virus the item which needs to be hit to win the game
     */
    Element* virus;
    /**
     * @brief balken potential obstacles, stored as a vector to enable iterating over them
     */
    QVector<Element*> balken;
    /**
     * @brief foehne additional items exerting forces on the ball, stored as a vector to enable iterating over them
     */
    QVector<Element*> foehne;
    QString Spielername;
private:
    /**
     * @brief currentBalken to accelerate the iteration over the vector
     */
    Element* currentBalken;
    /**
     * @brief currentBalkenItem to accelerate the iteration over the vector
     */
    Balken* currentBalkenItem;
    /**
     * @brief foehnBall a vector pointing from the tip of the foehn which is currently analysed to the ball
     */
    b2Vec2 foehnBall;
    /**
     * @brief distanceFoehnBall the projected distance of foehn and ball in direction of the foehn
     */
    int distanceFoehnBall;
    /**
     * @brief angleFoehnBall the angle between the direction of the foehn and the vector foehnBall
     */
    float angleFoehnBall;
    /**
     * @brief intensityFoehn the force acting on the ball through the foehn resulting from distance and angle
     */
    float intensityFoehn;
    /**
     * @brief isPaused whether the game is paused or not and thus if the animation should proceed
     */
    bool isPaused;



    /**
     * @brief Level::applyFoehnForces iterates over all foehne, checks whether the ball is in reach of them
     * and applies a force in direction of the foehn if necessary depending on the positions wrt each others
     */
    void applyFoehnForces();
    /**
     * @brief Level::updateB2Balken as the balken class only handles their Qt appearance/position,
     * their box2d position needs to be updated as well. Therefore this method iterates over all balken
     * stored in the QVector of the level and updates their position if the internal modified flag
     * has been set in the respective Qt-item.
     */
    void updateB2Balken();
};

#endif // LEVEL_H
