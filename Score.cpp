#include "Score.h"
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include <cmath>
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
    //we define the current level to be the largest integer smaller than the logarithm base 2 of the score
    int current_level = static_cast<int> (log(score)/log(2));
    if(game->level->getLevel()-1 < current_level) game->level->levelup();
}

int Score::getScore(){
    return score;
}
