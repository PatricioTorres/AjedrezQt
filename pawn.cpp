#include "pawn.h"
#include "game.h"
#include <QDebug>
#include <typeinfo>
extern game * juego;

Pawn::Pawn(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setImage();
    firstMove = true;
    type = "P";
}

void Pawn::setImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/pawnW.png"));
    else
        setPixmap(QPixmap(":/pawnB.png"));
}

void Pawn::resizeImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/pawnWm.png"));
    else
        setPixmap(QPixmap(":/pawnBm.png"));
}

void Pawn::moves()
{
    location.clear();

    int row = this->getCurrentBox()->rowLoc;

    int col = this->getCurrentBox()->colLoc;
    if(this->getTeam() == "WHITE")  {
        if(col > 0 && row > 0 && juego->collection[row-1][col-1]->getPieceColor() == "BLACK") {
            location.append(juego->collection[row-1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row > 0 && juego->collection[row-1][col+1]->getPieceColor() == "BLACK") {
            location.append(juego->collection[row-1][col+1]);
            boxSetting(location.last());
        }
        if(row>0 && (!juego->collection[row-1][col]->getHasPiece())) {
            location.append(juego->collection[row-1][col]);
            boxSetting(location.last());
            if(firstMove && !juego->collection[row-2][col]->getHasPiece()){
                location.append(juego->collection[row-2][col]);
                boxSetting(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && juego->collection[row+1][col-1]->getPieceColor() == "WHITE") {
            location.append(juego->collection[row+1][col-1]);
            boxSetting(location.last());
        }
        if(col < 7 && row <  7 && juego->collection[row+1][col+1]->getPieceColor() == "WHITE") {
            location.append(juego->collection[row+1][col+1]);
            boxSetting(location.last());
        }
        if(row<7 && (!juego->collection[row+1][col]->getHasPiece())) {
            location.append(juego->collection[row+1][col]);
            boxSetting(location.last());
            if(firstMove && !juego->collection[row+2][col]->getHasPiece()){
                location.append(juego->collection[row+2][col]);
                boxSetting(location.last());
            }

        }

    }

}
