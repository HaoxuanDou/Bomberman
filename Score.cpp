#include "Score.h"
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include "Game.h"

extern Game* game;
Score::Score(){
    score = 0;//defalut score to be 0

    //draw the text
    setPlainText("Score: " + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setPos(10*BLOCKSIZE,HEIGHT*BLOCKSIZE);
    setFont(QFont("times",25));
}

void Score::increase(){
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore(){
    return score;
}
