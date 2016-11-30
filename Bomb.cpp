#include "Bomb.h"
#include "Wave.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>

//const int BLOCKSIZE = 40;

extern Game* game;
Bomb::Bomb(int x, int y, int blast){
    //setup the image of the bomb
    setPixmap(QPixmap(":/images/bomb.png").scaled(BLOCKSIZE,BLOCKSIZE));

    X = x;
    Y = y;
    setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
    Blast = blast;

    //use a QTimer and connect to set up the explsion 1 seconds after the initialization
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Explode()));
    timer->start(1000);//1500 milliseconds are 1 seconds
}

void Bomb::Explode(){
    //blow up at the center
    Wave* wave = new Wave(X,Y);
    scene()->addItem(wave);
    //make waves to the left
    for(int i=1;i<=Blast;i++){
        if(game->map->getValue(X-i,Y) != 1){
            Wave* wave = new Wave(X-i,Y);
            scene()->addItem(wave);
        }else break;
    }
    //make waves to the right
    for(int i=1;i<=Blast;i++){
        if(game->map->getValue(X+i,Y) != 1){
            Wave* wave = new Wave(X+i,Y);
            scene()->addItem(wave);
        }else break;
    }
    //make waves to the top
    for(int i=1;i<=Blast;i++){
        if(game->map->getValue(X,Y-i) != 1){
            Wave* wave = new Wave(X,Y-i);
            scene()->addItem(wave);
        }else break;
    }
    //make waves to the bottom
    for(int i=1;i<=Blast;i++){
        if(game->map->getValue(X,Y+i) != 1){
            Wave* wave = new Wave(X,Y+i);
            scene()->addItem(wave);
        }else break;
    }

    scene()->removeItem(this);
    delete this;
}
