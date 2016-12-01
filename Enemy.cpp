#include "Enemy.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include <stdlib.h>
extern Game* game;
//const int BLOCKSIZE = 40;
void Enemy::move(){
    //the enemy moves randomly to left,right,up and down
    int random_number = rand()%4;
    if(random_number == 0){
        if(game->map->getValue(X-1,Y) == 0){
            X-=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(random_number == 1){
        if(game->map->getValue(X+1,Y) == 0){
            X+=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(random_number == 2){
        if(game->map->getValue(X,Y+1) == 0){
            Y+=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }else if(random_number == 3){
        if(game->map->getValue(X,Y-1) == 0){
            Y-=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
        }
    }
}

Enemy::Enemy(int x, int y){
    X = x;
    Y = y;
    //setup the initial image of the player
    setPixmap(QPixmap(":/images/enemy.png").scaled(BLOCKSIZE,BLOCKSIZE));
    //spawn the enemy
    setPos((x-1)*BLOCKSIZE,(y-1)*BLOCKSIZE);
    //connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);
}
