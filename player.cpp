#include "Player.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>

//the initial position of the player
const int INI_X = 8;
const int INI_Y = 12;
//We make the size of a player image to be 40*40
const int BLOCKSIZE = 40;

extern std::unique_ptr<Map> map;
Player::Player(){
    //setup the initial image of the player
    setPixmap(QPixmap(":/images/p_1_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
    setPos((INI_X-1)*BLOCKSIZE,(INI_Y-1)*BLOCKSIZE);

}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":/images/p_1_left.png").scaled(BLOCKSIZE,BLOCKSIZE));

    }else if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":/images/p_1_right.png").scaled(BLOCKSIZE,BLOCKSIZE));
    }else if(event->key() == Qt::Key_Up){
        setPixmap(QPixmap(":/images/p_1_up.png").scaled(BLOCKSIZE,BLOCKSIZE));
    }else if(event->key() == Qt::Key_Down){
        setPixmap(QPixmap(":/images/p_1_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
    }
}
