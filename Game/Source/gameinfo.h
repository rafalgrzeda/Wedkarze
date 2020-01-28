#ifndef GAMEINFO_H
#define GAMEINFO_H
/**
 * @brief Klasa GameInfo
 *Zawiera podstawowe informację na temat gry
 */

class GameInfo
{
private:
    /**
     * @brief level Aktualny lewel
     */
    int level;
    /**
     * @brief moneyCollected zdobyte pieniądze
     */
    int moneyCollected;
    /**
     * @brief moneyToNextLevel ilosc potrzebnych pieniedzy do przejscia poziomu
     */
    int moneyToNextLevel;
    /**
     * @brief loadMoneyToNext Wczytuje pieniadze lewelu z pliku tekstowego.
     */
    void loadMoneyToNext();
public:   
    GameInfo();
    /**
     * @brief increaseLevel zwieksza poziom o 1
     */
    void increaseLevel();
    /**
     * @brief getLevel Zwraca lewel
     * @return zwracany lewel
     */
    int getLevel();
    /**
     * @brief setMoneyCollected ustawia ilosc zdobytych pieniedzy
     * @param money zdobyte pieniadze
     */
    void setMoneyCollected(int money);
    /**
     * @brief addMoney dodaje pieniądze do zdobytych pieniędzy przez graczy
     * @param money ilość dodanych pieniędzy
     */
    void addMoney(int money);
    /**
     * @brief getMoneyCollected Zwraca ilosc zdobytych pięniedzy przez graczy
     * @return
     */
    int getMoneyCollected();
    /**
     * @brief getMoneyToNext zwraca ilosc pieniedzy potrzebnych do przejscia na nastepny level
     * @return
     */
    int getMoneyToNext();
    /**
     * @brief newGame Wczytuje pierwszy poziom
     */
    void newGame();

};

#endif // GAMEINFO_H
