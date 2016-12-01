#include "Player.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "map.h"
#include "Bomb.h"
#include "Enemy.h"
#include "Game.h"
#include <QDebug>
#include <stdlib.h>
//the initial position of the player
const int INI_X = 8;
const int INI_Y = 12;
//We make the size of a player image to be 40*40
//const int BLOCKSIZE = 40;

extern Game* game;
void Player::spawn(){
    //spawn the enemy randomly at the 4 corners of the map
    int random_number = rand()%4;
    if(random_number == 0){
        Enemy* enemy = new Enemy(2,2);
        scene()->addItem(enemy);
    }else if(random_number == 1){
        Enemy* enemy = new Enemy(2,14);
        scene()->addItem(enemy);
    }else if(random_number == 2){
        Enemy* enemy = new Enemy(14,14);
        scene()->addItem(enemy);
    }else if(random_number == 3){
        Enemy* enemy = new Enemy(14,2);
        scene()->addItem(enemy);
    }
}

Player::Player(){
    Blast = 1;//the power of the bomb is intialized to be 1
    //setup the initial image of the player
    setPixmap(QPixmap(":/images/p_1_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
    //postion the player to the initial location
    X = INI_X;
    Y = INI_Y;
    setPos((INI_X-1)*BLOCKSIZE,(INI_Y-1)*BLOCKSIZE);

    //spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(2000);

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
