#include "game.h"
#include "rendergame.h"
#include <QDebug>
#include "fish.h"
Game::Game()
{
    //Renderowanie planszy
    render = new RenderGame();

    enterEnable = 0;

    // Tworzenie wędek
    rightRope = new Rope();
    rightRope->setStartX(0.638*1366);
    rightRope->setStartY(0.09074*768);
    render->addRopeToScene(rightRope);
    connect(rightRope,SIGNAL(objectCought(int)),this,SLOT(addMoney(int)));


    leftRope = new Rope();
    leftRope->setStartX(0.35*1366);
    leftRope->setStartY(0.09074*768);
    render->addRopeToScene(leftRope);
    connect(leftRope,SIGNAL(objectCought(int)),this,SLOT(addMoney(int)));

    //Obsluga klawiszy
    connect(render,SIGNAL(buttonClicked(char)),this,SLOT(buttonClicked(char)));

    // Dodanie stopera
    stopwatch = new StopWatch();
    stopwatch->setPos(1200,10);
    render->addStopWatchToScene(stopwatch);

    connect(stopwatch,SIGNAL(endLevel()),this,SLOT(endLevel()));

    //Game info
    gameInfo = new GameInfo();
    render->updateGameInfo(gameInfo);

    // Level
    level = new Level(1);
    render->addLevelToScene(level);

    //Wyswietlenie
    render->show();
}

Game::~Game()
{
}

void Game::newLevel()
{
    // Reset Stopera
    stopwatch->reset();

    // GameInfo
    gameInfo->increaseLevel();
    render->updateGameInfo(gameInfo);

    // Wczytanie nowego levela
    level = new Level(gameInfo->getLevel());
    render->addLevelToScene(level);
}

void Game::newGame()
{
    gameInfo->newGame();
    stopwatch->start();
    render->updateGameInfo(gameInfo);

    level = new Level(gameInfo->getLevel());
    render->addLevelToScene(level);

    enterEnable = 0;
}



void Game::buttonClicked(char key)

{
    if(key == 'S'){
        if(leftRope->getThrown())
            qDebug() << "Throw left rope";
            leftRope->throwRope();
    }
    if(key == 'L'){
        if(rightRope->getThrown())
            qDebug() << "Throw right rope";
            rightRope->throwRope();
    }
    if(key == 'E' && enterEnable){
        qDebug() << "Start new Game";
        render->deleteEndGameMessage();
        newGame();
    }
}

void Game::addMoney(int money)
{
   gameInfo->addMoney(money);
   render->updateGameInfo(gameInfo);
}

void Game::endLevel()
{

    qDebug() << "End level";
    render->removeLevelFromScene(level);
    delete  level;
    if(gameInfo->getMoneyCollected() >= gameInfo->getMoneyToNext()){
        qDebug() << "Loading next level";
        newLevel();
    }

    else{
        qDebug() << "You lost";
        stopwatch->reset();
        stopwatch->stop();
        enterEnable = 1;
        // Komunikaty
        render->endGameMessage();
   }
}

