#include "info.h"
#include "button.h"
#include "definitions.h"
#include <QPainter>

info::info(int type, Button* closeinfo, QGraphicsRectItem* bounds)
{
    closeinfolocal=closeinfo;
///depending on the level, draw the info text
if(type==1){
  setPlainText(QString("Oh nein! ein geheimnisvoller Virus breitet sich aus und nur du hast den helfenden Antikörper-Ball. Zum Glück hast du deine Feder dabei, mit der du die Antikörper zum Virus schießen kannst. Wenn du die Feder anklickst, kannst du sie mit den Pfeiltasten steuern, mit der Leertaste feuerst du sie ab. Und wenn du gut bist, kannst du sogar unterwegs noch ein paar Masken für deine Freunde einsammeln. Jetzt heißt es also nur noch: GET THE VIRUS!"));

}

if(type==2){
  setPlainText(QString("Der geheimnisvolle Virus hat deine Absichten durchschaut und stellt dir jetzt Hindernisse in den Weg. Versuche sie aus dem Weg zu schaffen und vielleicht kannst du sie ja sogar für deine Absichten ausnutzen. Probiere es aus!"));

}



if(type==3){
  setPlainText(QString("Ein Sturm zieht auf: Versuche mit den Föhnen den Ball in die richtige Richtung zu bewegen, dann kannst du auf dem Weg zum Virus noch alle Masken einsammeln. Sie werden durch anklicken aktiviert!"));



}
adjustSize();
setPos(0,WINDOW_H-boundingRect().height()-closeinfo->boundingRect().height());
closeinfo->setPos(this->boundingRect().width()-closeinfo->boundingRect().width(),WINDOW_H-closeinfo->boundingRect().height());
bounds->setRect(this->x(),this->y(), this->boundingRect().width(),this->boundingRect().height());
}

void info::OKpressed()
{   ///deletes the info when called
    this->deleteLater();
    closeinfolocal->deleteLater();

}
