#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include <QGraphicsTextItem>

/**
 * @brief Klasa DisplayText
 *Wyświetla tekst w grze
 */
class DisplayText : public QGraphicsTextItem
{
public:
    /**
     * @brief Konstruktor DisplayText
     * @param _text wyświeltany tekst
     */
    DisplayText(QString _text);
    /**
     * @brief Metoda getText
     * @return zwraca tekst
     */
    QString getText() const;
    /**
     * @brief Metoda setText
     * @param value tekst to ustawienia
     */
    void setText(const QString &value);

private:
    QString text;
};

#endif // DISPLAYTEXT_H
