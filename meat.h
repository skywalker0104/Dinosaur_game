#ifndef MEAT_H
#define MEAT_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>

class Meat :public QObject,  public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Meat();
    qreal x() const;
signals:
    void collideFail();
    
public slots:
    void setX(qreal x);
    void deleteMeat();
    void freezeMeat();


private:
    bool collidesWithDinosaur();
    QPropertyAnimation * xAnimation;
    qreal m_x;
    QGraphicsPixmapItem * obMeat;
};

#endif // MEAT_H
