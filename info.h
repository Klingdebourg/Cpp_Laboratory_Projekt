#ifndef INFO_H
#define INFO_H
#include <QGraphicsTextItem>
#include "button.h"

class info:public QGraphicsTextItem
{
    Q_OBJECT
public:
    info(int type, Button* closeinfo, QGraphicsRectItem* bounds);
    Button* closeinfolocal;
    QGraphicsRectItem* boundslocal;

public slots:
    void OKpressed();
};

#endif // INFO_H
