#ifndef WAVE_H
#define WAVE_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Wave: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wave(int X, int Y);
public slots:
    void gone();//blast lasts and be gone
};

#endif // WAVE_H
