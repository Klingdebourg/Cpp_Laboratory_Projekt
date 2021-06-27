#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    ///
    /// \brief Button Der Konstruktor für Button
    /// \param name Dies ist ein Übergabeparameter mit dem Titel für den Button
    /// \param parent Zu übergeben an das Elternteil QGraphicsItem
    ///
    Button(QString name, QGraphicsItem* parent=NULL);

    ///
    /// \brief mousePressEvent
    /// \param event
    ///
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    ///
    /// \brief gettext: Gibt den Text/Titel des Buttons als QString zurück
    /// \return
    ///
    QString gettext();
signals:
    ///
    /// \brief clicked: Signal das der Button aussendet umd zu bestimmten Slot zu weisen
    ///
    void clicked();
private:
    ///
    /// \brief text: Private Variable in das der Name des Buttons gespeichert wird
    ///
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
