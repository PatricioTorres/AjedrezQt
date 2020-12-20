#ifndef MOVES_H
#define MOVES_H
#include <QGraphicsSimpleTextItem>
#include <iostream>

class moves:public QGraphicsSimpleTextItem
{
public:
    moves(QGraphicsItem *parent=0);
    moves(int x, int y, QString &text, QGraphicsItem *parent=0);
    moves(int x, int y, QString &text, QColor color, QGraphicsItem *parent=0);
    //moves& operator = (const moves &m);
    void rePos(int x, int y);
    void draw();

private:
    int rowLoc;
    int colLoc;
    QString text;
};

#endif // MOVES_H
