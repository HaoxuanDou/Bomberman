#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public slots:
    void spawn();
    void detect();//detect bomb wave
public:
    Player();
    int getX();
    int getY();
    void bombxplode();//reduce the bombcount;
    void touchEnemy();//detect enemy encounters
    void keyPressEvent(QKeyEvent* event);
    void blastUp();//increase the bomb power when levelup
    void reduceEnemy();//reduce the enemy count when a enemy dies
private:
    int bombCount = 0;//the bomb count in the map
    int enemyCount;//the enemy count in the map
    //the position of the player
    int X;
    int Y;
    int Blast;//the power of the player
};

#endif // PLAYER_H
