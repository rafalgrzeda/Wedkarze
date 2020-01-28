#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <waterobject.h>

/**
 * @brief Klasa Bomb
 *Obiekt wodny typu bomba
 */
class Bomb : public WaterObject
{
public:
    /**
     * @brief Konstruktor klasy Bomb
     * @param _width szerokość obiektu
     * @param _height wyskość obiektu
     * @param _image  wyswietlany obraz
     * @param _money  pieniądze dodane po złapaniu
     */
    Bomb(int _width, int _height, QPixmap _image, int _money);
    /**
     * @brief Metoda explode
     * Wybucha bombę niszcząć obiektu dokoła
     */
    void explode();
    /**
     * @brief Metoda getExploded
     * Sprawdza status bomby
     * @return 1- wybuchła, 0 - nie wybuchła
     */
    bool getExploded() const;

private:
    bool exploded;
};

#endif // BOMB_H
