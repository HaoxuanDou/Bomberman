#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem{
public:
    Player();
    void keyPressEvent(QKeyEvent* event);
private:
    //the position of the player
    int X;
    int Y;
};

#endif // PLAYER_H
