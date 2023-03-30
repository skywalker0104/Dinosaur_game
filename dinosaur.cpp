#include "dinosaur.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>


Dinosaur::Dinosaur(QPixmap pixmap):
    legDirection(0)
{
    status = "stand";
    jumpingsound = new QMediaPlayer();
    jumpingsound->setMedia(QUrl("qrc:/jumping.wav"));
    landingsound = new QMediaPlayer();
    landingsound->setMedia(QUrl("qrc:/landing.wav"));
    invisiblesound = new QMediaPlayer();
    invisiblesound->setMedia(QUrl("qrc:/invisibleSfx.wav"));
    gameoversound = new QMediaPlayer();
    gameoversound->setMedia(QUrl("qrc:/gameoversound.wav"));
    setPixmap(pixmap);
    dinosaurLegTimer = new QTimer(this);
    connect(dinosaurLegTimer, SIGNAL(timeout()), this, SLOT(updatePixmap()));
    dinosaurLegTimer->start(100);
    groundPosition = scenePos().y();
    yAnimation = new QPropertyAnimation(this, "y", this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
    yAnimation->start();
}


void Dinosaur::jump()
{
    if(status == "stand")
    {
        status = "jumping";
        yAnimation->stop();
        jumpingsound->play();
        qreal curPosY = y();
        yAnimation->setStartValue(curPosY);
        yAnimation->setEndValue(curPosY - 95);
        yAnimation->setEasingCurve(QEasingCurve::OutQuad);
        yAnimation->setDuration(500);
        connect(yAnimation, SIGNAL(finished()), this, SLOT(fall()));
        yAnimation->start();
    }
}

void Dinosaur::freezeDinosaur()
{
    status = "stop";
    yAnimation->stop();
    dinosaurLegTimer->stop();
    scene()->removeItem(this);
    gameoversound->play();
}

qreal Dinosaur::y() const
{
    return m_y;
}

void Dinosaur::fall()
{
    if(y() < groundPosition){
        if(status == "jumping")
        {
            qreal curPosY = y();
            yAnimation->setStartValue(curPosY);
            yAnimation->setEasingCurve(QEasingCurve::OutQuad);
            yAnimation->setEndValue(groundPosition);
            yAnimation->setDuration(300);
            yAnimation->start();
            landingsound->play();
        }
        status = "stand";
    }
}

void Dinosaur::back2Normal()
{
    if(status == "onfire"){
        status = "stand";
    }
}

void Dinosaur::updatePixmap()
{
    if(status == "stand"){
        if(legDirection){
            setPixmap(QPixmap("://image/dinosaur1.png"));
            legDirection = 0;
        }else{
            setPixmap(QPixmap("://image/dinosaur2.png"));
            legDirection = 1;
        }
    }
    else if(status == "onfire"){
        if(legDirection){
            setPixmap(QPixmap("://image/dinosaur3.png"));
            legDirection = 0;
        }else{
            setPixmap(QPixmap("://image/dinosaur4.png"));
            legDirection = 1;
        }
    }
}

void Dinosaur::setY(qreal y)
{
    moveBy(0, y-m_y);
    m_y = y;
}


void Dinosaur::fly()
{
    if(status == "stand")
    {
        status = "onfire";
        invisiblesound->play();
    }
}
