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
    void setConfig(int x, int y, QString &text, QColor color);
    void rePos(int x, int y);
    void reText(QString &text);
    void draw();

private:
    int rowLoc;
    int colLoc;
    QString text;
};

#endif // MOVES_H
