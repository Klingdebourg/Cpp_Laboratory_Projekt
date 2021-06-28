#ifndef BALKEN_H
#define BALKEN_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>

#include <math.h>

#include "definitions.h"




class Balken : public QGraphicsRectItem {
public:
    /**
     * @brief The balkenType enum defines whether and if yes how the balken can be
     * modified by the player
     */
    enum balkenType {
        statisch,
        translatorisch,
        rotatorisch
    };

    /**
     * @brief The modification enum this parameter is necessary to tell the level class
     * if a balken has been modifiedand if yes how. Then the level class will also modify
     * the position of the box2d instance of the balken
     */
    enum modification {
        LEFT,
        RIGHT,
        NONE
    };

    /**
     * @brief Balken simple constructor
     * @param x position of the balken
     * @param y position of the balken
     * @param rotation initial rotation of the balken
     * @param length the length of the balken
     * @param typ how the balken can be modified by the player
     */
    Balken(int x, int y, int rotation, int length = BALKEN_LENGTH_DEFAULT, balkenType typ = statisch);
    /**
     * @brief boundingRect implements virtual function
     * @return the area which contains the balken if it needs to be (re-)drawn
     */
    QRectF boundingRect() const;
    /**
     * @brief keyPressEvent moves or rotates the Balken if it is in focus
     * @param event contains the pressed key
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief mousePressEvent enables the object to be modified with keyboard input
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief paint implements virtual function to draw the balken according to certain requirements
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief setPosition sets the position of the Balken and changes the internally stored position
     * @param point
     */
    void setPosition(QPointF point);
    /**
     * @brief unmodified sets the modified status to NONE
     */
    void unmodified();
    /**
     * @brief setRotation alters the rotation of the Qt internal object while also altering the member
     * variable storing the current rotation
     * @param angle the new desired angle
     */
    void setRotation(qreal angle);

    /**
     * @brief getRotation simple getter method
     * @return current rotation of the Balken
     */
    int getRotation() const;
    /**
     * @brief getLength simple getter method
     * @return the current length of the balken
     */
    int getLength() const;
    /**
     * @brief getType simple getter method
     * @return the type of the balken
     */
    balkenType getType() const;
    /**
     * @brief wasModified simple getter method
     * @return how the balken was modified by the user during the last step of the box2d world
     */
    modification wasModified() const;

private:
    /**
     * @brief position the current position of the balken
     */
    QPointF position;
    /**
     * @brief rotation the current rotation of the balken
     */
    int rotation;
    /**
     * @brief length the length of the balken
     */
    int length;
    /**
     * @brief type the type of the balken
     */
    balkenType type;
    /**
     * @brief type to show the level if the balken has been modified in order to update its box2d body
     */
    modification modified;
};

#endif // BALKEN_H
