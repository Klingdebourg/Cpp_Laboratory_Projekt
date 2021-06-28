#ifndef FOEHN_H
#define FOEHN_H

#include <QGraphicsPolygonItem>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>

#include "definitions.h"


class Foehn : public QGraphicsPolygonItem{
public:
    Foehn(int x, int y, int alpha);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief boundingRect implements virtual function
     * @return the area which contains the foehn if it needs to be (re-)drawn
     */
    QRectF boundingRect() const;
    /**
     * @brief paint implements virtual function to draw the foehn according to certain requirements
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); 
    /**
     * @brief isOn simple getter for bool foehn_on
     * @return if the foehn is turned on or not
     */
    bool isOn() const;
private:
    /**
     * @brief triangle contains the coordinates for the Qt object triangle
     */
    QPolygon *triangle;
    /**
     * @brief foehn_on if the foehn is turned on or not
     */
    bool foehn_on = false;
};

#endif // FOEHN_H
