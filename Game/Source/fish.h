#ifndef FISH_H
#define FISH_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <waterobject.h>
/**
 * @brief Klasa Fish
 */
class Fish : public WaterObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor Fish
     * @param _width  szerokosc obietku
     * @param _height wysokosc obiektu
     * @param _image  wyswietlana grafika
     * @param _money ilosc pieniedzy dodanych po zlapaniu
     */
    Fish(int _width, int _height, QPixmap _image,int _money) ;
    /**
     * @brief Metoda stopMoving
     * Zatrzymuje rybę
     */
    void stopMoving();
private:
    /**
     * @brief back
     * Okresla ruch ryby prawo/lewo
     */
    bool back;
    QTimer *timer;

public slots:
    /**
   * @brief move
   * Animacja ruchu ryby
   */
  void move();

};

#endif // FISH_H
