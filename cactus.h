#ifndef CACTUS_H
#define CACTUS_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsScene>

class Cactus : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
    explicit Cactus();
    qreal x() const;
    void freezeCactus();

signals:
    void collideFail();
    
public slots:
    
    void setX(qreal x);
    void deleteCactus();

private:

    bool collidesWithDinosaur();

    QGraphicsPixmapItem * Cactuss;
    QPropertyAnimation * xAnimation;

    qreal m_x;
};

#endif // CACTUS_H
