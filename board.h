
#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsRectItem>
#include "box.h"
#include "piece.h"
class board
{

public:
    board();
    void drawBoxes(int x, int y);
    void drawCaptureBoxes(int x, int y, bool team);
    void drawTables();
    void addPiece();
    void setUpWhite();
    void setUpBlack();
private:
    QList <Piece *> white;
    QList <Piece *> black;


};

#endif // BOARD_H
