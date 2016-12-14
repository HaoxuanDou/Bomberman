#ifndef ENDTEXT_H
#define ENDTEXT_H
#include <QGraphicsTextItem>

class EndText: public QGraphicsTextItem{
public:
    EndText();
    void keyPressEvent(QKeyEvent* event);
};

#endif // ENDTEXT_H
