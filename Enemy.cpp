#include "Enemy.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include "Wave.h"
#include <QList>
#include <stdlib.h>
extern Game* game;
//const int BLOCKSIZE = 40;
void Enemy::move(){
    //the enemy moves towards the player or moves randomly
    //while(true){
    int x = game->player->getX() - X;//indicating the x-direction towards the player
    int y = game->player->getY() - Y;//indicating the y-direction towards the player
    bool flag = true;

    //int random_number = rand()%2;
    if(x<0&&flag){
        if(game->map->getValue(X-1,Y) == 0){
            X-=1;
            setPixmap(QPixmap(":/images/p_2_left.png").scaled(BLOCKSIZE,BLOCKSIZE));
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchPlayer();
            flag = false;
            //break;
        }
    }if(x>0&&flag){
        if(game->map->getValue(X+1,Y) == 0){
            X+=1;
            setPixmap(QPixmap(":/images/p_2_right.png").scaled(BLOCKSIZE,BLOCKSIZE));
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchPlayer();
            flag = false;
            //break;
        }
    }if(y>0&&flag){
        if(game->map->getValue(X,Y+1) == 0){
            Y+=1;
            setPixmap(QPixmap(":/images/p_2_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchPlayer();
            flag = false;
            //break;
        }
    }if(y<0&&flag){
        if(game->map->getValue(X,Y-1) == 0){
            Y-=1;
            setPixmap(QPixmap(":/images/p_2_up.png").scaled(BLOCKSIZE,BLOCKSIZE));
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchPlayer();
            flag = false;
            //break;
        }
    }
    //}
}

void Enemy::detect(){
    //if an enemy collides with wave, remove the enemy and score++
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(size_t i = 0, n= colliding_items.size(); i<n;++i){
        if(typeid(*(colliding_items[i])) == typeid(Wave)){
            game->score->increase();
            // remove
            scene()->removeItem(this);
            game->player->reduceEnemy();//reduce the enemy count
            //delete
            delete this;
            return;
        }
    }
}

Enemy::Enemy(int x, int y){
    X = x;
    Y = y;
    //setup the initial image of the player
    setPixmap(QPixmap(":/images/p_2_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
    //spawn the enemy
    setPos((x-1)*BLOCKSIZE,(y-1)*BLOCKSIZE);
    //move the enemy randomly every 300 mseconds
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(300);

    //detect blast wave every 100 mseconds
    QTimer* timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(detect()));
    timer2->start(100);
}

void Enemy::touchPlayer()
{
    //if player collides with enemy or wave, health--
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(size_t i = 0, n= colliding_items.size(); i<n;++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            game->health->decrease();
        }
    }
}
