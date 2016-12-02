#include "Health.h"
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include "Game.h"

extern Game* game;
Health::Health(){
    health = 10;//defalut health to be 10

    //draw the text
    setPlainText("Health: " + QString::number(health)); // Score: 0
    setDefaultTextColor(Qt::white);
    setPos(10,HEIGHT*BLOCKSIZE);
    setFont(QFont("times",25));
}

void Health::decrease(){
    health--;
    setPlainText("Health: " + QString::number(health));

    if(health == 0){
        gameover();
    }
}

int Health::getHealth(){
    return health;
}

void Health::gameover(){

}


