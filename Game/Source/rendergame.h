#ifndef RENDERGAME_H
#define RENDERGAME_H

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "rope.h"
#include "waterobject.h"
#include "displaytext.h"
#include "stopwatch.h"
#include "level.h"
#include "gameinfo.h"
#include <QGraphicsTextItem>
#include <QPushButton>

/**
 * @brief Klasa RenderGame
 * Klasa odpowiadająca za wyświetlanie gry
 */

class RenderGame : public QGraphicsView
{
    Q_OBJECT
public:
    RenderGame();
    /**
     * @brief keyPressEvent Sprawdza, czy jakiś klawisz został wciśniety, a jak tak to jaki
     * @param event
     */
    void keyPressEvent(QKeyEvent *event);
    /**
     * @brief addRopeToScene Dodanie wędki do widoku gry
     * @param rope wskaźnik do dodawanego obiektu
     */
    void addRopeToScene(Rope *rope);
    /**
     * @brief addObjectToScene Dodaje obiekt wodny do widoku gry
     * @param obj wskaźnik do dodawanego obiektu
     */
    void addObjectToScene(WaterObject *obj);
    /**
     * @brief addStopWatchToScene Dodaje stoper do widoku gry
     * @param stopwach wskaźnik do dodawanego obiektu
     */
    void addStopWatchToScene(StopWatch *stopwach);
    /**
     * @brief addLevelToScene dodanie lewelu wraz z wszystkimi obiektami do widoku gry
     * @param level wskaźnik do dodawanego lewelu
     */
    void addLevelToScene(Level *level);
    /**
     * @brief removeLevelFromScene Usuwa lewel z widoku gry
     * @param level wskaźnik do usuwanego lewelu
     */
    void removeLevelFromScene(Level *level);
    /**
     * @brief updateGameInfo uaktualnia parametry gry w widoku
     * @param info wskaźnik do obiektu GameInfo
     */
    void updateGameInfo(GameInfo *info);
    /**
     * @brief endGameMessage Wyswietla komunikat po zakonczeiu gry
     */
    void endGameMessage();
    /**
     * @brief deleteEndGameMessage Usuniecie komunikatu zakonczenia gry
     */
    void deleteEndGameMessage();
private:
    QGraphicsScene *scene;
    QGraphicsTextItem * level;
    QGraphicsTextItem * moneyToNext;
    QGraphicsTextItem * moneyCollected;
    QGraphicsTextItem * msg;
    QGraphicsTextItem * msg_newGame;

signals:
    void buttonClicked(char key);
};

#endif // RENDERGAME_H
