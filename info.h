#ifndef INFO_H
#define INFO_H
#include <QGraphicsTextItem>
#include "button.h"

class info:public QGraphicsTextItem
{
    Q_OBJECT
public:
    /**
     * @brief info constructor
     * @param type to distinguish which level it is
     * @param closeinfo the button given to the class
     * @param bounds RectItem to be given to the class
     *
     * This class governs the info text displayed in each level the player sees when he starts playing
     */
    info(int type, Button* closeinfo, QGraphicsRectItem* bounds);


public slots:
    /**
     * @brief OKpressed slot is called when the player presses OK and wants the info to be closed
     */
    void OKpressed();
private:
    /**
     * @brief closeinfolocal local copy of the button closeinfo to use it (was originally initialized in level.cpp)
     */
    Button* closeinfolocal;

};

#endif // INFO_H
