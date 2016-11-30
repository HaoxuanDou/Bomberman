#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsPixmapItem>
//We make the size of a block image to be 40*40
//const int BLOCKSIZE = 40;

class Block: public QGraphicsPixmapItem{
public:
    Block(const int X, const int Y);//the constructor takes in the posiiton of the block

};


#endif // BLOCK_H
