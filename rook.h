#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook:public Piece
{
public:
    Rook(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void resizeImage();
    void moves();

};
#endif // ROOK_H
