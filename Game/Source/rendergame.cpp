#include "rendergame.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cstdlib>
#include <ctime>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
#include "fish.h"
#include "rope.h"
#include "QDebug"
#include "waterobject.h"
#include "bomb.h"
#include "stopwatch.h"
#include <QObject>
#include <game.h>
#include "displaytext.h"

RenderGame::RenderGame()
{
    // Ustawienia okna
    setFixedSize(1365,760);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //Stworzenie sceny
    scene = new QGraphicsScene();

    //Ustawienie tła
    QImage background(":/img/Grafika/background.jpg");
    setBackgroundBrush(QBrush(background.scaled(1366,768,Qt::KeepAspectRatio)));

    // set scene
    setScene(scene);
    scene->setSceneRect(0,0,1365,760);

    // Wyswietlanie dla GameInfo
    QFont myfont;
    myfont.setPixelSize(20);
    myfont.setBold(true);

    level = new QGraphicsTextItem("Level");
    scene->addItem(level);
    level->setPos(140,35);
    level->setFont(myfont);

    moneyCollected = new QGraphicsTextItem("Money");
    scene->addItem(moneyCollected);
    moneyCollected->setPos(140,75);
    moneyCollected->setFont(myfont);

    moneyToNext = new QGraphicsTextItem("Gold");
    moneyToNext->setScale(0.8);
    scene->addItem(moneyToNext);
    moneyToNext->setPos(140,128);
    moneyToNext->setFont(myfont);
}

void RenderGame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S){
        qDebug() << "S clicked";
        emit buttonClicked('S');
    }
    if(event->key() == Qt::Key_L){
        qDebug() << "L clicked";
        emit buttonClicked('L');
    }
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        qDebug() << "ENTER clicked";
        emit buttonClicked('E');
    }
}

void RenderGame::addRopeToScene(Rope *rope)
{
    scene->addItem(rope);
}

void RenderGame::addObjectToScene(WaterObject *obj)
{
    scene->addItem(obj);
}

void RenderGame::addStopWatchToScene(StopWatch *stopwach)
{

    scene->addItem(stopwach);
}

void RenderGame::addLevelToScene(Level *level)
{
    QList<WaterObject*> list = level->getWaterObjectList();
    for(int i = 0; i < list.size();i++){
        scene->addItem(list.at(i));
        bool colision = 0;
        colision = list.at(i)->isCollidated();
        while(colision){
            list.at(i)->setRandomPos();
            colision = list.at(i)->isCollidated();
        }
    }
}

void RenderGame::removeLevelFromScene(Level *level)
{
    QList<WaterObject*> list = level->getWaterObjectList();
    qDebug() << list.size();
    for(int i = 0; i < list.size();i++){
        scene->removeItem(list.at(i));
        delete list.at(i);
    }
}

void RenderGame::updateGameInfo(GameInfo *info)
{
    int t_level = info->getLevel();
    int t_moneyCollected = info->getMoneyCollected();
    int t_moneyToNext = info->getMoneyToNext();

    level->setPlainText(QString::number(t_level));
    moneyToNext->setPlainText(QString::number(t_moneyToNext));
    moneyCollected->setPlainText(QString::number(t_moneyCollected));
}

void RenderGame::endGameMessage()
{
    QFont myfont;
    myfont.setPixelSize(40);
    myfont.setBold(true);

    msg = new QGraphicsTextItem("You lost");
    scene->addItem(msg);
    msg->setPos(600,400);
    msg->setFont(myfont);

    myfont.setPixelSize(18);
    msg_newGame = new QGraphicsTextItem("Press ENTER to start new game");
    scene->addItem(msg_newGame);
    msg_newGame->setPos(546,450);
    msg_newGame->setFont(myfont);
}

void RenderGame::deleteEndGameMessage()
{
    delete msg;
    delete msg_newGame;
}



