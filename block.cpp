#include "Block.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>

const int BLOCKSIZE = 40;
Block::Block(const int X, const int Y){
    //setup the image of the block
    setPixmap(QPixmap(":/images/rock.png").scaled(BLOCKSIZE,BLOCKSIZE));
    setPos((X-1)*BLOCKSIZE,(Y-1)*BLOCKSIZE);
}
