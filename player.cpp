#include "Player.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "map.h"
#include "Bomb.h"
#include "Game.h"
#include <QDebug>
//the initial position of the player
const int INI_X = 8;
const int INI_Y = 12;
//We make the size of a player image to be 40*40
//const int BLOCKSIZE = 40;

extern Game* game;
Player::Player(){
    Blast = 1;//the power of the bomb is intialized to be 1
    //setup the initial image of the player
    setPixmap(QPixmap(":/images/p_1_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
    //postion the player to the initial location
    X = INI_X;
    Y = INI_Y;
    setPos((INI_X-1)*BLOCKSIZE,(INI_Y-1)*BLOCKSIZE);

}

void Player::keyPressEvent(QKeyEvent *event){
    //move the player or drop a bomb based on the key pressed
    if(event->key() == Qt::Key_Left){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_left.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X-1,Y) == 0){
            X-=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(event->key() == Qt::Key_Right){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_right.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X+1,Y) == 0){
            X+=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(event->key() == Qt::Key_Up){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_up.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X,Y-1) == 0){
            Y-=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(event->key() == Qt::Key_Down){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X,Y+1) == 0){
            Y+=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(event->key() == Qt::Key_Space){
        Bomb* bomb = new Bomb(X,Y,Blast);
        scene()->addItem(bomb);
    }
}
