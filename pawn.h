#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn:public Piece
{
public:
    Pawn(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void resizeImage();
    void moves();

};

#endif // PAWN_H
