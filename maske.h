#ifndef MASKE_H
#define MASKE_H

#include <QGraphicsRectItem>
#include <QPainter>

#include "definitions.h"

class Maske : public QGraphicsRectItem {
public:
    /**
     * @brief Maske regular constructor
     * @param x position of the maske
     * @param y position of the maske
     */
    Maske(int x, int y);
    /**
     * @brief boundingRect implements virtual function
     * @return the area which contains the maske if it needs to be (re-)drawn
     */
    QRectF boundingRect() const;
    /**
     * @brief paint implements virtual function to draw the maske according to certain requirements
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MASKE_H
