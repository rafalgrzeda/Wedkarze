#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "rendergame.h"
#include "rope.h"
#include "level.h"
#include "gameinfo.h"

/**
 * @brief Klasa Game
 * Klasa odpowiadająca za całą grę
 */

class Game : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor klas gra
     * Ma za zadanie wczytanie wszystkich podstawowych parametrów gry
     */
    Game();
    ~Game();
private:
    RenderGame *render;
    Rope *leftRope;
    Rope *rightRope;
    Level *level;
    GameInfo *gameInfo;
    StopWatch *stopwatch;
    /**
     * @brief enterEnable
     * Włącza i wyłącza przycisk ENTER
     * Podczas gry wyłączony, podczas oczekiwania na nową grę włączony
     */
    bool enterEnable;
    /**
     * @brief Metoda newLevel
     * Metoda, która zwiększa lewel o 1. A następnie wczytuję ten lewel.
     */
    void newLevel();
    /**
     * @brief Metoda newGame
     * Po przegranej grze. Tworzy nową rozgrywkę
     */
    void newGame();
private slots:
    /**
     * @brief Metoda buttonClicked
     * Metoda, która odbiera wciśnietę przyciski przez gracza
     * @param key Znak wciśnietego przycisku
     */
    void buttonClicked(char key);
    /**
     * @brief Metoda addMoney
     * @param money Ilosc dodanego zlota
     */
    void addMoney(int money);
    /**
     * @brief Metoda endLevel
     * Sprawdza czy gracz może przejsc na następny poziom. Wywoływana po zakończeniu poziomu.
     */
    void endLevel();
};

#endif // GAME_H
