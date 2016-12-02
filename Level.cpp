#include "Level.h"
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include "Game.h"

extern Game* game;
Level::Level(){
    level = 1;//defalut level to be 1

    //draw the text
    setPlainText("Level: " + QString::number(level));
    setDefaultTextColor(Qt::white);
    setPos(5*BLOCKSIZE,HEIGHT*BLOCKSIZE);
    setFont(QFont("times",25));
}

int Level::getLevel()
{
    return level;
}

void Level::levelup()
{
    level++;
    setPlainText("Level: " + QString::number(level));

    game->player->blastUp();//increase the bomb power
}


