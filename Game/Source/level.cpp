#include "level.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QDebug>
#include <QString>
#include <fish.h>
#include <bomb.h>
Level::Level(int _level)
{
    level = _level;
    loadLevel();
}

QList<WaterObject *> Level::getWaterObjectList()
{
    return objectList;
}

void Level::removeObjectFromList(WaterObject *obj)
{
    objectList.removeOne(obj);
    qDebug() << "Wielkosc listy:" + QString::number(objectList.size());
}

Level::~Level()
{

}

void Level::loadLevel()
{
    int i = 0;
    std:: string line;
    std::ifstream myfile ("levelInfo.txt");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            if(i == level){
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

    int count = 0;
    //Ryby
    for(int i = 1; i <= list.at(2).toInt();i++){
        QPixmap img(":/img/Grafika/orange_fish.png");
        Fish * fish = new Fish(120,90,img,250);
        objectList.append(fish);
        connect(fish,SIGNAL(removed(WaterObject*)),this,SLOT(removeObjectFromList(WaterObject*)));
        count++;
    }
    qDebug() << "Ryby: " + QString::number(count);
    count = 0;
    //Bomby
    for(int i = 1; i <= list.at(3).toInt();i++){
        QPixmap img(":/img/Grafika/bomb.png");
        Bomb *bomb = new Bomb(90,120,img,0);
        objectList.append(bomb);
        connect(bomb,SIGNAL(removed(WaterObject*)),this,SLOT(removeObjectFromList(WaterObject*)));
        count++;
    }
    qDebug() << "Bomby: " + QString::number(count);
    count = 0;
    //Buty
    for(int i = 1; i <= list.at(4).toInt();i++){
        QPixmap img(":/img/Grafika/kalosze.png");
        WaterObject *boots = new WaterObject(90,120,img,50);
        objectList.append(boots);
        connect(boots,SIGNAL(removed(WaterObject*)),this,SLOT(removeObjectFromList(WaterObject*)));
        count++;
    }
    qDebug() << "Buty: " + QString::number(count);
    count = 0;
    //Algi
    for(int i = 1; i <= list.at(5).toInt();i++){
        QPixmap img(":/img/Grafika/alga.png");
        WaterObject *alga = new WaterObject(90,180,img,25);
        objectList.append(alga);
        connect(alga,SIGNAL(removed(WaterObject*)),this,SLOT(removeObjectFromList(WaterObject*)));
        count++;
    }
    qDebug() << "Algi: " + QString::number(count);
    count = 0;
}


