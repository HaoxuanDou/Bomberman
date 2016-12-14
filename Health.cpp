#include "Health.h"
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include "Endtext.h"
#include "Game.h"

extern Game* game;
Health::Health(){
    health = 20;//defalut health to be 20

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
    //the starting scene
    game->endScene = new QGraphicsScene();
    //set the size of the scene
    game->endScene->setSceneRect(0,0,WIDTH*BLOCKSIZE,(HEIGHT+1)*BLOCKSIZE);
    //set the background color to be green
    game->endScene->setBackgroundBrush(Qt::black);
    //set the end title
    QGraphicsTextItem* title = new QGraphicsTextItem();
    title->setPos(45,50);
    title->setDefaultTextColor(Qt::white);
    title->setPlainText("Your Score: "+ QString::number(game->score->getScore()));
    title->setFont(QFont("times",30));
    //set the start directions
    EndText* endtext = new EndText();
    endtext->setFlag(QGraphicsItem::ItemIsFocusable);
    endtext->setFocus();
    game->endScene->addItem(title);
    game->endScene->addItem(endtext);
    game->setScene(game->endScene);
}


