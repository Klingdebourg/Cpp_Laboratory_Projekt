#ifndef INFO_H
#define INFO_H
#include <QGraphicsTextItem>
#include "button.h"

class info:public QGraphicsTextItem
{
    Q_OBJECT
public:
    ///
    /// \brief info
    /// \param type
    /// \param closeinfo
    /// \param bounds
    ///
    info(int type, Button* closeinfo, QGraphicsRectItem* bounds);


public slots:
    ///
    /// \brief OKpressed
    ///
    void OKpressed();
private:
    ///
    /// \brief closeinfolocal
    ///
    Button* closeinfolocal;
    ///
    /// \brief boundslocal
    ///
    QGraphicsRectItem* boundslocal;
};

#endif // INFO_H
