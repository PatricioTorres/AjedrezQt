#ifndef MOVES_H
#define MOVES_H
#include <QGraphicsSimpleTextItem>
#include <iostream>

class moves:public QGraphicsSimpleTextItem
{
public:
    moves(QGraphicsItem *parent=0);
    void draw();
    int rowLoc;
    int colLoc;
};

#endif // MOVES_H
