#ifndef KING_H
#define KING_H

#include "piece.h"
#include "pawn.h"

class king:public Piece
{
public:
    king(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void resizeImage();
    void moves();
    void SafeLocation();

};

#endif // KING_H
