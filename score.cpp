#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):
    QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Press Start 2P", 10));
}

void Score::increase()
{
    score += 10;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::endGame()
{
    setPlainText(QString("GAME OVER!\n"));
}

int Score::getScore()
{
    return score;
}
