#ifndef ROPE_H
#define ROPE_H

#include <QObject>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include <waterobject.h>

/**
 * @brief Klasa Rope Klasa odpowiadające za obiekt wędka
 */
class Rope : public QObject,public QGraphicsLineItem
{
    Q_OBJECT
public:
    Rope();
    /**
     * @brief ropePos ustawia pozycję wędki
     */
    void ropePos();
    /**
     * @brief throwRope rozpoczęcie animacji strzelenia wędką
     */
    void throwRope();
    /**
     * @brief getStartX Zwraca wartość X puntku zaczepenia wędki
     * @return
     */
    int getStartX() const;
    /**
     * @brief setStartX Ustawia wartość X puntku zaczepenia wędki
     * @param value
     */
    void setStartX(int value);
    /**
     * @brief getStartY zwraca wartość Y punktu zaczepienia wędki
     * @return
     */
    int getStartY() const;
    /**
     * @brief setStartY Ustaiwa wartosc Y punktu zaczepienia wędki
     * @param value
     */
    void setStartY(int value);
    /**
     * @brief getThrown Sprawdza czy wędka zostałą rzucona
     * @return
     */
    bool getThrown() const;
    /**
     * @brief setThrown Ustawia status wędki
     * @param value     1 - rzucona 0 - nie
     */
    void setThrown(bool value);

private:
    /**
     * @brief startX Punkt X zaczepienia wędki
     */
    int startX;
    /**
     * @brief startY Punkt Y zaczepienia wędki
     */
    int startY;
    /**
     * @brief R długość wędki
     */
    int R;
    /**
     * @brief angle Kąt wychylenia wędki
     */
    double angle;
    QTimer *timer;

    /**
     * @brief colision Sprawdza kolizje z innymi obiektami
     * @param actualX  Koniec wędki - X
     * @param actualY  Koniec wędki - Y
     */
    void colision(double actualX,double actualY);
    // Do animacji
    /**
     * @brief back oscylacja wędki prawo - lewo
     */
    bool back;
    /**
     * @brief backLine wartość boolean, czy wedka wraca po wystrzeleniu
     */
    bool backLine;
    /**
     * @brief thrown czy wedka jest wystrzelona
     */
    bool thrown;
public slots:
    /**
     * @brief oscillate animacja ruchu oscylacyjnego wędki
     */
    void oscillate();
    /**
     * @brief throwLine animacja wystrzelenia wędki
     */
    void throwLine();

public: signals:
    void objectCought(int money);


};

#endif // ROPE_H
