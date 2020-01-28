#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>

/**
 * @brief Klasa StopWatch
 * Odlicza czas końca jednego poziomu
 */
class StopWatch : public QGraphicsTextItem
{
    Q_OBJECT
public:
    StopWatch();
    /**
     * @brief reset reset stopera
     */
    void reset();
    /**
     * @brief start uruchomienie stopera
     */
    void start();
    /**
     * @brief stop zatrzymanie stopera
     */
    void stop();
private:
    QTimer *timer;
    /**
     * @brief time aktualny czas
     */
    int time;
public slots:
    /**
     * @brief timeElapsed aniamcja upływu czasu
     */
    void timeElapsed();
signals:
    void endLevel();
};

#endif // STOPWATCH_H
