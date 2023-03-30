#include "scene.h"
#include <QKeyEvent>
#include <stdlib.h>
#include <QDebug>

Scene::Scene(QObject *parent) :
    QGraphicsScene(parent)
{
    setUpCactusTimer();
    setUpMeatTimer();
}

void Scene::addDinosaur()
{
    dinosaur = new Dinosaur(QPixmap("://image/dinosaur.png"));
    dinosaur->setPos(QPointF(20, 50) - QPoint(dinosaur->boundingRect().width()/8, dinosaur->boundingRect().height()/12));
    addItem(dinosaur);
}


void Scene::addScore()
{
    score = new Score();
    score->setPos(QPointF(420, -180));
    addItem(score);
    endgame = new Score();
    endgame->setPos(QPointF(200, 200));
    addItem(endgame);
}

void Scene::setUpCactusTimer()
{
    cactusTimer = new QTimer(this);
    cactusTimer->start(2000);
    connect(cactusTimer, SIGNAL(timeout()), this, SLOT(move()));
    scoreTimer = new QTimer(this);
    scoreTimer->start(500);
    connect(scoreTimer, SIGNAL(timeout()), this, SLOT(updateScore()));
}

void Scene::setUpMeatTimer()
{
    meatTimer = new QTimer(this);
    meatTimer->start(25000);
    connect(meatTimer, SIGNAL(timeout()), this, SLOT(move2()));
}

void Scene::move()
{
    Cactus * cactus = new Cactus();
    addItem(cactus);
    connect(cactus, SIGNAL(collideFail()), SLOT(freeze()));
}

void Scene::move2()
{
    Meat * meat = new Meat();
    addItem(meat);
    connect(meat, SIGNAL(collideFail()), SLOT(skill()));
}

void Scene::freeze()
{
    if(dinosaur->status != "onfire")
    {
        cactusTimer->stop();
        meatTimer->stop();
        dinosaur->freezeDinosaur();
        scoreTimer->stop();
        QList<QGraphicsItem*> sceneItems = items();
        foreach (QGraphicsItem * item, sceneItems){
            Cactus * cactus = dynamic_cast<Cactus*>(item);
            if(cactus){
                cactus->freezeCactus();
            }
        }
    }
}

void Scene::updateScore()
{
    score->increase();
}

void Scene::skill()
{
    dinosaur->fly();
    QList<QGraphicsItem*> sceneItems = items();
    foreach (QGraphicsItem * item, sceneItems){
        Meat * meat = dynamic_cast<Meat*>(item);
        if(meat){
            meat->freezeMeat();
        }
    }
    fireTimer = new QTimer(dinosaur);
    fireTimer->start(9000);
    connect(fireTimer, SIGNAL(timeout()), dinosaur, SLOT(back2Normal()));
}


void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        dinosaur->jump();
    }

}
