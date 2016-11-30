#include "Game.h"
#include "Map.h"
#include "Block.h"
#include "Player.h"
#include "Bomb.h"
#include <QGraphicsView>
#include <vector>
#include <memory>


//We make the brackground to be of the size 15 blocks by 15 blocks, with each block of size 40*40
Game::Game(){
    //creating a new scene
    //scene =std::unique_ptr<QGraphicsScene>(new QGraphicsScene());
    scene = new QGraphicsScene();

    //set the size of view and scene to be the preferred size
    setFixedSize(WIDTH*BLOCKSIZE,(HEIGHT+1)*BLOCKSIZE);
    scene->setSceneRect(0,0,WIDTH*BLOCKSIZE,(HEIGHT+1)*BLOCKSIZE);

    //set the background color to be green, representing the field on which the game takes place
    scene->setBackgroundBrush(Qt::darkGreen);

    //set up a map
    map = std::unique_ptr<Map>(new Map());
    //constructing the initial gameplay background and permmenant blocks
    Block* temp;
    for(int i=1; i<=WIDTH;i++){
        for(int j=1; j<=HEIGHT; j++){
            if(map->getValue(i,j) == 1){
                //std::unique_ptr<Block> temp = std::unique_ptr<Block>(new Block(i,j));
                temp = new Block(i,j);
                blockVec.push_back(temp);
                scene->addItem(blockVec[blockVec.size()-1]);
            }
        }
    }

    player = new Player();
    scene->addItem(player);
    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();





    setScene(scene);


}
