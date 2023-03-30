#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "dinosaur.h"
#include <QTimer>
#include "cactus.h"
#include "score.h"
#include "meat.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);

    void addDinosaur();
    
    void addCactus();

    void startGame();
    void addScore();
    void addExplosion();


signals:
    
public slots:
    void move();
    void move2();
    void freeze();
    void updateScore();
    void skill();
private:
    void setUpCactusTimer();
    void setUpMeatTimer();
    Dinosaur * dinosaur;
    QTimer * cactusTimer;
    Score * score;
    Score * endgame;
    QTimer * scoreTimer;
    QTimer * meatTimer;
    QTimer * fireTimer;


protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // SCENE_H
