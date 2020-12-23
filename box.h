#ifndef BOX_H
#define BOX_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <iostream>
#include "piece.h"

class Piece;
class box:public QGraphicsRectItem
{
public:
    box(QGraphicsItem *parent=0);
    int rowLoc;
    int colLoc;
    void setOriginalColor(QColor value);
    void setColor(QColor color);
    void resetOriginalColor();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Piece * currentPiece;
    QString getPieceColor() ;
    ~box();
    void setPieceColor(QString value);
    bool getHasPiece();
    void setHasPiece(bool value,Piece *piece = 0);
    void placePiece(Piece *piece);
    void capturePiece(Piece *piece);
    void movedPiece(Piece *piece, bool& capture);
     void VeriCheck();
private:
    QBrush brush;
    QColor originalColor;
    QString PieceColor;
    bool hasPiece;

};

#endif // BOX_H
