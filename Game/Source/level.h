#ifndef LEVEL_H
#define LEVEL_H
#include <waterobject.h>

/**
 * @brief Klasa Level
 *Klasa jednego lewela w grze
 */
class Level : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstuktor klasy Level
     * @param _level Wczytywany lewel
     */
    Level(int _level);
    /**
     * @brief getWaterObjectList Zwraca listę obiektów wodnych aktualnie wykorzystywanych
     * @return
     */
    QList<WaterObject *> getWaterObjectList();
    ~Level();
private:
    /**
     * @brief level nr lewela
     */
    int level;
    /**
     * @brief objectList lista zawierajaca wszystkie aktualnie wykorzystywane obiekty(ryby,algi,buty,bomby)
     */
    QList <WaterObject*> objectList;
    /**
     * @brief loadLevel Wczytuję lewel z pliku. Uzupełnia listę obiektów.
     */
    void loadLevel();
private slots:
    /**
     * @brief removeObjectFromList Usuwa obiekt z listy
     * @param obj Usuwany obiekt
     */
    void removeObjectFromList(WaterObject *obj);
};

#endif // LEVEL_H
