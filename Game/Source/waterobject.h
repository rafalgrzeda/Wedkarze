#ifndef WATEROBJECT_H
#define WATEROBJECT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QList>
/**
 * @brief Klasa WaterObject
 * Definiuje elemty wodne, które mogą być złapane przed wędke
 */
class WaterObject :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    WaterObject(int _width, int _height, QPixmap _image, int _money, double xPos = 0, double yPos = 0);
    ~WaterObject();

    /**
     * @brief setRandomPos ustawienie losowej pozycji na planszy
     */
    void setRandomPos();
    /**
     * @brief catched Uruchamia animację powrotu obietku do wędki
     * @param _anmiationCoordinates wspolrzednie wędki
     */
    void catched(QList <double> _anmiationCoordinates);
    /**
     * @brief isCollidated Sprawdza kolizje z innymi obiektami
     * W momencie losowania ustawienia obiektów na planszy sprawdza czy nie pokrywa się on z innym obiektem
     * @return
     */
    bool isCollidated();
    /**
     * @brief getWidth zwraca szerokosc obiektu
     * @return  szerokosc obiektu
     */
    int getWidth() const;
    /**
     * @brief setWidth ustawia szerokosc obiettu
     * @param value szerokosc obiektu
     */
    void setWidth(int value);
    /**
     * @brief getXPos Zwraca warotść X obiektu
     * @return Pozycja - X
     */
    double getXPos() const;
    /**
     * @brief setXPos Ustawia wartosc X obietku
     * @param value Pozycja - X
     */
    void setXPos(double value);

    /**
     * @brief getYPos Zwraca wartosc Y obiektu
     * @return Pozycja - Y
     */
    double getYPos() const;
    /**
     * @brief setYPos Ustawia wartosc Y obiektu
     * @param value Pozycja - Y
     */
    void setYPos(double value);
    /**
     * @brief getHeight zwraca wysokosc obietku
     * @return  wysokosc obietku
     */
    int getHeight() const;
    /**
     * @brief setHeight ustaiwa wysokosc obiektu
     * @param value wysokosc
     */
    void setHeight(int value);
    /**
     * @brief getMoney zwraca wartość pieniężną obiektu
     * @return pieniądze
     */
    int getMoney() const;
    /**
     * @brief setMoney ustawia wartość pinieżną obiektu
     * @param value pieniądze
     */
    void setMoney(int value);

protected:
    int width;
    int height;
    double xPos;
    double yPos;
    QPixmap image;
    int money;
private:
    // to animation
    QTimer *timer;
    /**
     * @brief anmiationCoordinates lista wspolrzednych
     *     double startX = anmiationCoordinates.value(0);   // dokąd X
           double startY = anmiationCoordinates.value(1);   // dokąd Y
           double acutalX = anmiationCoordinates.value(2);  // aktualna pozycja X
           double acutalY = anmiationCoordinates.value(3);  // aktualna pozycja Y
           double R = anmiationCoordinates.value(4);
           double angle = anmiationCoordinates.value(5);
     */
    QList <double> anmiationCoordinates;

public slots:
    /**
     * @brief goUp animacja złapania przez wędkę
     */
    void goUp();
signals:
    void removed(WaterObject*);
};

#endif // WATEROBJECT_H
