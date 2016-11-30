#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>


class Player: public QGraphicsPixmapItem{
public:
    Player();
    void keyPressEvent(QKeyEvent* event);
private:

};

#endif // PLAYER_H
