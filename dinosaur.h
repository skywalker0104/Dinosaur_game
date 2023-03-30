#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QMediaPlayer>

class Dinosaur : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal y READ y WRITE setY)

public:
    explicit Dinosaur(QPixmap pixmap);
    qreal y() const;
    void jump();
    QString status;
    void freezeDinosaur();
    void startRunning();
    void fly();


signals:
    
public slots:

    void setY(qreal y);
    void fall();
    void back2Normal();
    void updatePixmap();


private:
    int legDirection; //0: left, 1: right

    qreal m_y;
    qreal groundPosition;
    QPropertyAnimation * yAnimation;
    QMediaPlayer * jumpingsound;
    QMediaPlayer * landingsound;
    QMediaPlayer * invisiblesound;
    QMediaPlayer * gameoversound;
    QTimer * dinosaurLegTimer;
};

#endif // DINOSAUR_H
