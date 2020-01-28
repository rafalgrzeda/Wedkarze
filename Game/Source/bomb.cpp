#include "bomb.h"
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QGraphicsScene>
#include <QList>
#include <fish.h>
Bomb::Bomb(int _width, int _height, QPixmap _image, int _money)
    : WaterObject(_width,_height,_image, _money)
{
    exploded = 0;
}

void Bomb::explode()
{
    exploded = 1;
    qDebug() << "Explode";

    QPixmap boom(":/img/Grafika/explosion_range.jpg");
    setPixmap(boom.scaled(width*3,height*3,Qt::KeepAspectRatio)); // powiekszenie obszaru

    QList<QGraphicsItem *> colliding_items = collidingItems(); // sprawdzenie kolizji z tym obszarem
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if ((typeid(*(colliding_items[i])) == typeid(WaterObject)) || (typeid(*(colliding_items[i])) == typeid(Fish))){
            qDebug() << "Bomb destroyed object";
            // Usuniecie ze sceny
            scene()->removeItem(colliding_items[i]);
            // Usuniecie z list level
            WaterObject *obj = dynamic_cast<WaterObject*>(colliding_items[i]);
            obj->removed(obj);
            delete colliding_items[i];
            }
    }
    // Niszczenie bomby
    scene()->removeItem(this);
    emit removed(this);
    delete this;
}

bool Bomb::getExploded() const
{
    return exploded;
}
