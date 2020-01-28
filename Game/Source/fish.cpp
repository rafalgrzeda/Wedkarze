#include "fish.h"
#include <QTimer>
#include "game.h"
#include <QDebug>
#include <rendergame.h>

Fish::Fish(int _width, int _height, QPixmap _image, int _money)
    : WaterObject(_width,_height,_image,_money)
{
    back = 0;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Fish::stopMoving()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
}

void Fish::move()
{
    QPixmap fish(":/img/Grafika/orange_fish.png");
    QPixmap fish2(":/img/Grafika/orange_fish2.png");

    if(pos().x() > 0 && back == 0){
        setPos(x()-10,y());
    }
    if(pos().x() <= 0 && back == 0){
        setPixmap(fish2.scaled(width,height,Qt::KeepAspectRatio));
        back = 1;
    }
    if(pos().x()  < (1820 - width) && back == 1){
        setPos(x() + 10,y());
    }
    if(pos().x() >= (1820 - width) && back == 1){
        back = 0;
        setPixmap(fish.scaled(width,height,Qt::KeepAspectRatio));
    }
}






