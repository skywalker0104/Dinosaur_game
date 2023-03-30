#include "meat.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include <QDebug>
#include "dinosaur.h"

Meat::Meat():
    obMeat(new QGraphicsPixmapItem(QPixmap("://image/meat.png")))
{
    obMeat->setPos(QPointF(600, 80) + QPoint(obMeat->boundingRect().width()/8,
                                              obMeat->boundingRect().height()/12));
    int xRandom = 1000 + rand()%2000;
    setPos(QPoint(0, 0) + QPoint(200 + xRandom, 80));
    addToGroup(obMeat);
    xAnimation = new QPropertyAnimation(this, "x", this);
    xAnimation->setStartValue(200 + xRandom);
    xAnimation->setEndValue(-500);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(8000);
    connect(xAnimation, SIGNAL(finished()), this, SLOT(deleteMeat()));
    xAnimation->start();
}

qreal Meat::x() const
{
    return m_x;
}

void Meat::setX(qreal x)
{
    m_x = x;
    if(collidesWithDinosaur()){
        emit collideFail();
    }
    setPos(QPointF(0, 0) + QPointF(x, 80));
}

void Meat::deleteMeat()
{
    scene()->removeItem(this);
    delete this;
}

void Meat::freezeMeat()
{
    scene()->removeItem(obMeat);
}

bool Meat::collidesWithDinosaur()
{
    QList<QGraphicsItem*> collidingItems = obMeat->collidingItems();

    foreach (QGraphicsItem * item, collidingItems){
        Dinosaur * dinosaur = dynamic_cast<Dinosaur*>(item);
        if(dinosaur){
            return true;
        }
    }
    return false;
}
