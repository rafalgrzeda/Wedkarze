#include "waterobject.h"
#include <QTimer>
#include <QDebug>
#include <math.h>
#include <QtMath>
#include <QGraphicsScene>
WaterObject::WaterObject(int _width, int _height, QPixmap _image,int _money, double xPos, double yPos)
{
    width = _width;
    height = _height;
    image = _image;
    money = _money;

    setRandomPos();

    setPixmap(image.scaled(width,height,Qt::KeepAspectRatio));
    timer = new QTimer();
}

WaterObject::~WaterObject()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(goUp()));
}

void WaterObject::setRandomPos()
{
    xPos = rand() % 1160 + 40;
    yPos = rand() % 380 +250;
    setPos(xPos,yPos);
}

void WaterObject::catched(QList <double> _anmiationCoordinates)
{
    anmiationCoordinates = _anmiationCoordinates;
    connect(timer,SIGNAL(timeout()),this,SLOT(goUp()));
    timer->start(50);
}

bool WaterObject::isCollidated()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if ((typeid(*(colliding_items[i])) == typeid(WaterObject))){
            qDebug() << "Losuj jeszcze raz";
            return 1;
            }
    }
    return 0;
}


void WaterObject::goUp()
{
    /*
    Notatka
    double startX = anmiationCoordinates.value(0);   // dokąd X
    double startY = anmiationCoordinates.value(1);   // dokąd Y
    double acutalX = anmiationCoordinates.value(2);  // aktualna pozycja X
    double acutalY = anmiationCoordinates.value(3);  // aktualna pozycja Y
    double R = anmiationCoordinates.value(4);
    double angle = anmiationCoordinates.value(5);
    */

    if(anmiationCoordinates.value(4) > 200 ){
        double a = qCos(qDegreesToRadians(anmiationCoordinates.value(5)));
        double b = qSin(qDegreesToRadians(anmiationCoordinates.value(5)));
        anmiationCoordinates.replace(4 ,anmiationCoordinates.value(4) - 15); // na r
        anmiationCoordinates.replace(2,anmiationCoordinates.value(0)+anmiationCoordinates.value(4)*a); // podmiana x
        anmiationCoordinates.replace(3,anmiationCoordinates.value(1)+anmiationCoordinates.value(4)*b); // podmiana y
        setPos(anmiationCoordinates.value(2),anmiationCoordinates.value(3));
    }
    if(anmiationCoordinates.value(4) <= 200){
     scene()->removeItem(this);
     emit removed(this);
     delete this;
    }
}

int WaterObject::getMoney() const
{
    return money;
}

void WaterObject::setMoney(int value)
{
    money = value;
}

int WaterObject::getHeight() const
{
    return height;
}

void WaterObject::setHeight(int value)
{
    height = value;
}

void WaterObject::setWidth(int value)
{
    width = value;
}

double WaterObject::getYPos() const
{
    return yPos;
}

void WaterObject::setYPos(double value)
{
    yPos = value;
}

double WaterObject::getXPos() const
{
    return xPos;
}

void WaterObject::setXPos(double value)
{
    xPos = value;
}

int WaterObject::getWidth() const
{
    return width;
}
