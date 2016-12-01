#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public slots:
    void move();
public:
    Enemy(int x, int y);//the spawn the enemy at position x,y
private:
    int X;
    int Y;//the position of the enemy

};

#endif // ENEMY_H
