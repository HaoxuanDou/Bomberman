#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public slots:
    void spawn();
public:
    Player();
    void keyPressEvent(QKeyEvent* event);
private:
    //the position of the player
    int X;
    int Y;
    int Blast;//the power of the player
};

#endif // PLAYER_H
