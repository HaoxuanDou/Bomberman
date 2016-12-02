#include "Player.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include "Wave.h"
#include "map.h"
#include "Bomb.h"
#include "Enemy.h"
#include "Game.h"
#include "Health.h"
#include "Level.h"
#include "Score.h"
#include <QDebug>
#include <stdlib.h>
//the initial position of the player
const int INI_X = 8;
const int INI_Y = 12;
//We make the size of a player image to be 40*40
//const int BLOCKSIZE = 40;

extern Game* game;
void Player::spawn(){
    //the enemy allowed in the map is capped by the current level
    if(enemyCount < game->level->getLevel()){
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
        enemyCount++;
    }
}

void Player::detect(){
    //if player collides with enemy or wave, health--
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(size_t i = 0, n= colliding_items.size(); i<n;++i){
        if(typeid(*(colliding_items[i])) == typeid(Wave)){
            game->health->decrease();
        }
    }
}

Player::Player(){
    enemyCount = 0;//initially there is no enemy
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
    //detect touch with enemy and explosion waves
    QTimer* timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),this,SLOT(detect()));
    timer2->start(300);

}

void Player::touchEnemy(){
    //if player collides with enemy, health--
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(size_t i = 0, n= colliding_items.size(); i<n;++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->health->decrease();
        }
    }
}

void Player::keyPressEvent(QKeyEvent *event){
    //move the player or drop a bomb based on the key pressed
    if(event->key() == Qt::Key_Left){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_left.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X-1,Y) == 0){
            X-=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchEnemy();
        }
    }else if(event->key() == Qt::Key_Right){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_right.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X+1,Y) == 0){
            X+=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchEnemy();
        }
    }else if(event->key() == Qt::Key_Up){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_up.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X,Y-1) == 0){
            Y-=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchEnemy();
        }
    }else if(event->key() == Qt::Key_Down){
        //qDebug() << "Pressed";
        setPixmap(QPixmap(":/images/p_1_down.png").scaled(BLOCKSIZE,BLOCKSIZE));
        if(game->map->getValue(X,Y+1) == 0){
            Y+=1;
            setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
            touchEnemy();
        }
    }else if(event->key() == Qt::Key_Space){
        Bomb* bomb = new Bomb(X,Y,Blast);
        scene()->addItem(bomb);
    }
}

void Player::blastUp(){
    Blast++;
}

void Player::reduceEnemy(){
    enemyCount--;
}
