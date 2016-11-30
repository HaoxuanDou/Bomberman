#ifndef BOMB_H
#define BOMB_H
#include <QGraphicsPixmapItem>
#include <QObject>
//We make the size of a bomb image to be 40*40

class Bomb: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bomb(int x, int y, int blast);
public slots:
    void Explode();
private:
    int Blast;
    //the position of the bomb
    int X;
    int Y
};

#endif // BOMB_H
