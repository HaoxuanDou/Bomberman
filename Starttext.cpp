#include "Starttext.h"
#include "Score.h"
#include <QGraphicsTextItem>
#include <QTextBlockFormat>
#include <QTextOption>
#include <QString>
#include <QFont>
#include <QKeyEvent>
#include "Game.h"
extern Game* game;
StartText::StartText(){
    setPlainText("PRESS SPACE TO START"); // Set the intro direction of the game
    setDefaultTextColor(Qt::white);
    setPos(140,350);
    setFont(QFont("times",30));
}

void StartText::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Space){
        //the game scene scene
        game->scene = new QGraphicsScene();

        //set the size of the scene
        game->scene->setSceneRect(0,0,WIDTH*BLOCKSIZE,(HEIGHT+1)*BLOCKSIZE);

        //set the background color to be green, representing the field on which the game takes place
        game->scene->setBackgroundBrush(Qt::darkGreen);

        //set up a map
        game->map = std::unique_ptr<Map>(new Map());
        //constructing the initial gameplay background and permmenant blocks
        Block* temp;
        for(int i=1; i<=WIDTH;i++){
            for(int j=1; j<=HEIGHT; j++){
                if(game->map->getValue(i,j) == 1){
                    //std::unique_ptr<Block> temp = std::unique_ptr<Block>(new Block(i,j));
                    temp = new Block(i,j);
                    game->blockVec.push_back(temp);
                    game->scene->addItem(game->blockVec[game->blockVec.size()-1]);
                }
            }
        }

        game->player = new Player();
        game->scene->addItem(game->player);
        game->health = new Health();
        game->level = new Level();
        game->score = new Score();
        game->scene->addItem(game->health);
        game->scene->addItem(game->level);
        game->scene->addItem(game->score);

        //make player focusable
        game->player->setFlag(QGraphicsItem::ItemIsFocusable);
        game->player->setFocus();
        game->setScene(game->scene);

    }
}


