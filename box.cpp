#include "box.h"
#include "game.h"

extern game *juego;
box::box(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    //setHasChessPiece(false);
    //setChessPieceColor("NONE");
    //currentPiece = NULL;
}
void box::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}
void box::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}


