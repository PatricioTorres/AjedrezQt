#include "piece.h"
#include "game.h"
#include <QDebug>
#include "king.h"
extern game *juego;
Piece::Piece()
{

}

Piece::Piece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    Team = team;
    isPlaced = true;
    firstMove = true;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(this == juego->pieceToMove){
        juego->pieceToMove->getBox()->resetOriginalColor();
        juego->pieceToMove->color();
        juego->pieceToMove = NULL;
       return;
    }

    if((!getIsPlaced() )|| ( (juego->getTurn() != this->getTeam())&& (!juego->pieceToMove)) )
        return;

    if(!juego->pieceToMove){
        juego->pieceToMove = this;
        juego->pieceToMove->getBox()->setColor(Qt::red);
        juego->pieceToMove->moves();
    }

    else if(this->getTeam() != juego->pieceToMove->getTeam()){
        this->getBox()->mousePressEvent(event);
    }


}
void Piece::setCurrentBox(box *Box)
{

    currentBox = Box;
}
box *Piece::getCurrentBox()
{
    return currentBox;
}
box *Piece::getBox()
{
    return currentBox;
}
QString Piece::getTeam()
{
    return Team;
}
QString Piece::getType()
{
    return type;
}
QList<box *> Piece::moveLocation()
{
    return location;
}

bool Piece::getIsPlaced()
{
    return isPlaced;
}

void Piece::setIsPlaced(bool value)
{
    isPlaced = value;

}
bool Piece::boxSetting(box *box)
{
    if(box->getHasPiece()) {
        king *q = dynamic_cast<king*>(location.last()->currentPiece);
        if(q){
            box->setColor(Qt::blue);
        }
        else
            box->setColor(Qt::red);
        return true;
    }
    else
        location.last()->setColor(Qt::darkRed);
    return false;
}
