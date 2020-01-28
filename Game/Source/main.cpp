#include <QApplication>
#include "fish.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Stworzenie instancji Gra
    Game *game = new Game();

    return a.exec();
}
