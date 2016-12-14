#ifndef STARTTEXT_H
#define STARTTEXT_H
#include <QGraphicsTextItem>
#include <QTextOption>
class StartText: public QGraphicsTextItem{
public:
    StartText();
    void keyPressEvent(QKeyEvent* event);
};

#endif // STARTTEXT_H
