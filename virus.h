#ifndef VIRUS_H
#define VIRUS_H

#include "QGraphicsEllipseItem"
#include <QRectF>
#include <QPainter>

class Virus : public QGraphicsEllipseItem {
public:
    /**
     * @brief Virus regular consturctor
     * @param x position of the virus
     * @param y position of the virus
     */
    Virus(int x, int y);
    /**
     * @brief boundingRect implements virtual function
     * @return the area which contains the virus if it needs to be (re-)drawn
     */
    QRectF boundingRect() const;
    /**
     * @brief paint implements virtual function to draw the virus according to certain requirements
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // VIRUS_H
