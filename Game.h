#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <memory>
#include <vector>
#include "Game.h"
#include "Map.h"
#include "Block.h"
#include "Player.h"
#include "Bomb.h"

//each block is of size 40*40
const int BLOCKSIZE = 40;
//We make the brackground to be of the size 15 blocks by 19 blocks
const int WIDTH = 15;
const int HEIGHT = 15;

class Game: public QGraphicsView{
public:
    Game();
/*
    std::unique_ptr<QGraphicsScene> scene;
    std::unique_ptr<Map> map;
    std::vector<std::unique_ptr<Block>> blockVec;
*/
    QGraphicsScene* scene;
    Player* player;
    std::unique_ptr<Map> map;
    std::vector<Block*> blockVec;
};


#endif // GAME_H
