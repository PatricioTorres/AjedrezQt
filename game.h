#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "box.h"
#include <board.h>
class game:public QGraphicsView
{
    Q_OBJECT
public:
    game(QWidget *parent = 0);
    QGraphicsTextItem *check;
    box * collection[8][8];
    void displayMainMenu();
    void drawBoard();
    void drawDeadHolder(int x, int y, QColor color);
    void addItem(QGraphicsItem *item);
private:
    QGraphicsScene *Scene;
    QGraphicsTextItem * turnDisplay;
    board *chess;
    QGraphicsRectItem * deadHolder;

};

#endif // GAME_H
