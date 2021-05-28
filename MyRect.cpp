#include "MyRect.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include "Bullet.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MyRect know that you pressed a key";

    if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (event->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }
    else if (event->key() == Qt::Key_Space){
        //create a bullet
        Bullet * bullet = new Bullet();
        qDebug()<<"Bullet created";
        scene()->addItem(bullet);
    }
}
