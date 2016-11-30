#include "Bomb.h"
#include <QGraphicsPixmapItem>
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

    //use a QTimer and connect to set up the explsion 4 seconds after the initialization
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Explode()));
    timer->start(4000);//4000 milliseconds are 4 seconds
}

void Bomb::Explode(){
    //make waves to the left
    for(int i=1;i<=Blast;i++){
        if(game->map.getValue(X-i,Y) != 1){

        }
    }
}
