#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include "cactus.h"
#include "meat.h"
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(0, -150, 500, 300);
    QMovie *movie = new QMovie("://image/bg.gif");
    QLabel *processLabel = new QLabel();
    processLabel->setMovie(movie);
    processLabel->setGeometry(QRect(-85, -200, 800, 400));

    QGraphicsProxyWidget * awProxy = scene->addWidget(processLabel);
    movie->setSpeed(20);
    movie->start();

    scene->addDinosaur();
    scene->addScore();
    ui->graphicsView->setScene(scene);
}



Widget::~Widget()
{
    delete ui;
}
