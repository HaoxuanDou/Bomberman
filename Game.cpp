#include "Game.h"
#include "Map.h"
#include "Block.h"
#include "Player.h"
#include "Bomb.h"
#include "Health.h"
#include "Level.h"
#include "Starttext.h"
#include "Score.h"
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QFont>
#include <vector>
#include <memory>


//We make the brackground to be of the size 15 blocks by 15 blocks, with each block of size 40*40
Game::Game(){

    //set the size of view and scene to be the preferred size
    setFixedSize(WIDTH*BLOCKSIZE,(HEIGHT+1)*BLOCKSIZE);

    //the starting scene
    startScene = new QGraphicsScene();
    //set the size of the scene
    startScene->setSceneRect(0,0,WIDTH*BLOCKSIZE,(HEIGHT+1)*BLOCKSIZE);
    //set the background color to be green
    startScene->setBackgroundBrush(Qt::black);
    //set the title
    QGraphicsTextItem* title = new QGraphicsTextItem();
    title->setPos(45,50);
    title->setDefaultTextColor(Qt::white);
    title->setPlainText("HOMEMADE BOMBERMAN");
    title->setFont(QFont("times",40));
    //set the start directions
    StartText* starttext = new StartText();
    starttext->setFlag(QGraphicsItem::ItemIsFocusable);
    starttext->setFocus();
    startScene->addItem(title);
    startScene->addItem(starttext);
    setScene(startScene);
/*
    //the game scene scene
    scene = new QGraphicsScene();

    //set the size of the scene
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
    health = new Health();
    level = new Level();
    score = new Score();
    scene->addItem(health);
    scene->addItem(level);
    scene->addItem(score);

    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //setScene(scene);

*/

}
