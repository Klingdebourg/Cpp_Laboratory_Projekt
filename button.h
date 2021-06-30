#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    /**
     * @brief button constructor
     * @param name parameter given to the constructor containing the name of the button
     * @param parent to be given to the parent class
     */
    Button(QString name, QGraphicsItem* parent=NULL);

    /**
     * @brief mousePressEvent
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief gettext gives back the private variable text
     * @return the name of the button as a QString
     */
    QString gettext();
signals:
    /**
     * @brief clicked signal that is emitted when a button is clicked to show to the slot
     */
    void clicked();
private:
    /**
     * @brief text private variable that contains the name of the variable
     */
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
