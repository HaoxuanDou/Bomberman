#include "Wave.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

Wave::Wave(int X, int Y){
    //setup the image of the bomb
    setPixmap(QPixmap(":/images/explosion.png").scaled(BLOCKSIZE,BLOCKSIZE));
    setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);

    //use a QTimer and connect to set up the explosion wave be gone 0.5 seconds after the initialization
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(gone()));
    timer->start(500);
}
