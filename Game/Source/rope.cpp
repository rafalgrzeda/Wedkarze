#include "rope.h"
#include <QPen>
#include <QTimer>
#include <QDebug>
#include <QtMath>
#include <QKeyEvent>
#include <QList>
#include "waterobject.h"
#include "fish.h"
#include "bomb.h"
Rope::Rope()
{
    // Grubość linii
    QPen pen;
    pen.setWidth(2);
    this->setPen(pen);

    // Podstawowe parametry linii
    R = 200;
    angle = 90;
    back = 0;
    backLine = 0;
    thrown = 0;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(oscillate()));
    timer->start(60);
}

void Rope::ropePos()
{
    double a = qCos(qDegreesToRadians(angle));
    double b = qSin(qDegreesToRadians(angle));
    setLine(startX,startY,startX + R*a,startY + R*b);
}

void Rope::throwRope()
{
    if(!thrown){
        disconnect(timer,SIGNAL(timeout()),this,SLOT(oscillate()));
        connect(timer,SIGNAL(timeout()),this,SLOT(throwLine()));
    };

}

void Rope::oscillate()
{
    double actualX = 0;
    double actualY = 0;
    double a = 0;
    double b = 0;
    if(angle >= 46 && angle <= 136 && back ==0){
        angle = angle + 2;
        a = qCos(qDegreesToRadians(angle));
        b = qSin(qDegreesToRadians(angle));
        actualX = startX + R*a;
        actualY = startY + R*b;
        setLine(startX,startY,actualX,actualY);
    }
    if (angle >= 136 && back == 0) {
        back =1;
    }
    if(angle >= 46 && angle <= 136 && back ==1){
        angle = angle - 2;
        a = qCos(qDegreesToRadians(angle));
        b = qSin(qDegreesToRadians(angle));
        actualX = startX + R*a;
        actualY = startY + R*b;
        setLine(startX,startY,actualX,actualY);
    }
    if (angle <= 46 && back == 1) {
        back =0;
    }
}

void Rope::throwLine()
{
    double a = qCos(qDegreesToRadians(angle));
    double b = qSin(qDegreesToRadians(angle));
    double actualX = 0;
    double actualY = 0;
    thrown = 1;
    // move
    if(R <= 700 && backLine == 0){
        R = R + 25;
        actualX = startX + R*a;
        actualY = startY + R*b;
        setLine(startX,startY,actualX,actualY);
    }
    if(R >= 700 && backLine == 0){
        backLine = 1;
    }
    if(R < 750 && backLine == 1){
        R = R - 18;
        actualX = startX + R*a;
        actualY = startY + R*b;
        setLine(startX,startY,actualX,actualY);
    }
    if(R <= 200){
        backLine = 0;
        thrown  = 0;
        connect(timer,SIGNAL(timeout()),this,SLOT(oscillate()));
        disconnect(timer,SIGNAL(timeout()),this,SLOT(throwLine()));
    }

    // collision
    if(!backLine){
        colision(actualX,actualY);
    }

}

void Rope::colision(double actualX, double actualY)
{
    // Utowrzenie list kolidujacych obiektow
    QList<QGraphicsItem *> colliding_items = collidingItems();
    // Sprawdzenie jej
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        // Jesli to alga, but lub ryba
        if ((typeid(*(colliding_items[i])) == typeid(WaterObject)) || (typeid(*(colliding_items[i])) == typeid(Fish)) ){
            qDebug() << "Kolizja";
            backLine = 1;           // wroc wedke
            //Jesli to ryba
            if(typeid (*colliding_items[i]) == typeid (Fish)){
                Fish *collidated_item = (Fish*)colliding_items[i];
                if(collidated_item->getYPos() <= actualY  )
                    collidated_item->stopMoving(); // zatrzymaj rybę
                else
                    break;
            }
            //Powrót złapanego przedmiotu
            WaterObject *collidated_item = (WaterObject*)colliding_items[i];
            QList <double> animation ;
            animation.append(startX); animation.append(startY); animation.append(actualX); animation.append(actualY); animation.append(R); animation.append(angle);
            collidated_item->catched(animation); //animacja powrotu
            emit objectCought(collidated_item->getMoney());
            }
        // Jesli to bomba - nie wraca tylko wybucha
        if((typeid(*(colliding_items[i])) == typeid(Bomb))){
            backLine = 1;  // wroc wedke
            Bomb *collidated_item = (Bomb*)colliding_items[i];
            if(!collidated_item->getExploded()){  // jezeli bomba wczesniej nie eksplodowala
                collidated_item->explode();       //eksploduj
            }
        }
    }
}

bool Rope::getThrown() const
{
    return thrown;
}

void Rope::setThrown(bool value)
{
    thrown = value;
}

int Rope::getStartY() const
{
    return startY;
}

void Rope::setStartY(int value)
{
    startY = value;
}

int Rope::getStartX() const
{
    return startX;
}

void Rope::setStartX(int value)
{
    startX = value;
}
