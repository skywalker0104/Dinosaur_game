#include "cactus.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include <QDebug>
#include "dinosaur.h"

Cactus::Cactus():
    Cactuss(new QGraphicsPixmapItem(QPixmap("://image/bus.png")))
{

    Cactuss->setPos(QPointF(600, 80) + QPoint(Cactuss->boundingRect().width()/8,
                                              Cactuss->boundingRect().height()/12));
    int xRandom = 1000 + rand()%1500;
    setPos(QPoint(0, 0) + QPoint(200 + xRandom, 80));
    addToGroup(Cactuss);
    xAnimation = new QPropertyAnimation(this, "x", this);
    xAnimation->setStartValue(200 + xRandom);
    xAnimation->setEndValue(-500);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(8000);
    connect(xAnimation, SIGNAL(finished()), this, SLOT(deleteCactus()));
    xAnimation->start();
}



qreal Cactus::x() const
{
    return m_x;
}

void Cactus::freezeCactus()
{
    scene()->removeItem(Cactuss);
}

void Cactus::setX(qreal x)
{
    m_x = x;
    if(collidesWithDinosaur()){
        emit collideFail();
    }
    setPos(QPointF(0, 0) + QPointF(x, 80));
}

void Cactus::deleteCactus()
{
    scene()->removeItem(this);
    delete this;
}

bool Cactus::collidesWithDinosaur()
{
    QList<QGraphicsItem*> collidingItems = Cactuss->collidingItems();

    foreach (QGraphicsItem * item, collidingItems){
        Dinosaur * dinosaur = dynamic_cast<Dinosaur*>(item);
        if(dinosaur){
            return true;
        }
    }
    return false;
}
