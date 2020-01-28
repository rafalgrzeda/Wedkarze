#include "gameinfo.h"
#include <fstream>
#include <QString>
#include <QDebug>
#include <iostream>

GameInfo::GameInfo()
{
    level = 1;
    moneyCollected = 0;
    loadMoneyToNext();
}

void GameInfo::loadMoneyToNext()
{
    int i = 0;
    std:: string line;
    std::ifstream myfile ("levelInfo.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            if(i == level){
                qDebug() << QString::fromStdString(line);
                break;
            }
            i++;

        }
        myfile.close();
    }
    else{
        qDebug() << "Zla sciezka";
    }
    QString sline = QString::fromStdString(line);
    QStringList list = sline.split('\t');

    moneyToNextLevel = list.at(1).toInt();
    qDebug() << "Money to next level: " + QString::number(moneyToNextLevel);
}

void GameInfo::increaseLevel()
{
    level++;
    loadMoneyToNext();
}

int GameInfo::getLevel()
{
    return level;
}

void GameInfo::setMoneyCollected(int money)
{
    moneyCollected = money;
}

void GameInfo::addMoney(int money)
{
    moneyCollected = moneyCollected + money;
}

int GameInfo::getMoneyCollected()
{
    return moneyCollected;
}

int GameInfo::getMoneyToNext()
{
    return moneyToNextLevel;
}

void GameInfo::newGame()
{
    level = 1;
    moneyCollected = 0;
    loadMoneyToNext();
}
