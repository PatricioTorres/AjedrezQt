#ifndef HOURSE_H
#define HOURSE_H


#include "piece.h"

class horse:public Piece
{
public:
    horse(QString team,QGraphicsItem *parent = 0);
    void setImage();
    void resizeImage();
    void moves();

};

#endif // HOURSE_H
