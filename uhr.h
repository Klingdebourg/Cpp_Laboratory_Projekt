#ifndef UHR_H
#define UHR_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class Uhr : public QLCDNumber{
    Q_OBJECT
public:
    Uhr(QWidget *parent = nullptr);

private slots:
    void passedTime();
};


//class StopWatch : public QWidget
//{
//    Q_OBJECT
//public:
//    explicit StopWatch(QWidget * parent = 0)
//        : QWidget(parent)
//        , mRunning(false)
//        , mStartTime()
//    {
//        startTimer(0);
//    }

//public slots:
//    void start(void)
//    {
//        mStartTime = QDateTime::currentDateTime();
//        mRunning = true;
//    }

//    void stop(void)
//    {
//        mRunning = false;
//    }

//protected:
//    void timerEvent(QTimerEvent *)
//    {
//        if(mRunning)
//        {
//            qint64 ms = mStartTime.msecsTo(QDateTime::currentDateTime());
//            int h = ms / 1000 / 60 / 60;
//            int m = (ms / 1000 / 60) - (h * 60);
//            int s = (ms / 1000) - (m * 60);
//            ms = ms - (s * 1000);
//            QString diff = QString("%1:%2:%3:%4").arg(h).arg(m).arg(s).arg(ms);
//            mLabel->setText(diff);
//        }
//    }

//private:
//    bool mRunning;
//    QDateTime mStartTime;
//    QLabel * mLabel;
//};


#endif // UHR_H
