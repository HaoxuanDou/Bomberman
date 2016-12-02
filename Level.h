#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsTextItem>

class Level: public QGraphicsTextItem{
public:
    Level();
    int getLevel();
    void levelup();
private:
    int level;
};

#endif // LEVEL_H
