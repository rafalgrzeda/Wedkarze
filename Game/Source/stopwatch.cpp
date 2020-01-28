#include "stopwatch.h"
#include <QElapsedTimer>
#include <QDebug>
#include <QFont>
StopWatch::StopWatch()
{
    time = 30;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timeElapsed()));
    timer->start(1000);

    QFont myfont;
    myfont.setPixelSize(30);
    myfont.setBold(true);
    setFont(myfont);
}

void StopWatch::reset()
{
    time = 30;
}

void StopWatch::start()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(timeElapsed()));
    timer->start(1000);
}

void StopWatch::stop()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(timeElapsed()));
}

void StopWatch::timeElapsed()
{
    if(time == 0){
        qDebug() << "END TIME";
        emit endLevel();

    }
    setPlainText("Time: "+ QString::number(time));
    time = time - 1;
}
//love you
