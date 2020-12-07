#include "horse.h"
#include "game.h"
extern game * juego;


horse::horse(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setImage();
    type = "C";
}

void horse::setImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/horseW.png"));
    else
        setPixmap(QPixmap(":/horseB.png"));
}
void horse::resizeImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/horseWm.png"));
    else
        setPixmap(QPixmap(":/horseBm.png"));
}

void horse::moves()
{
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    int i ,j;
    QString team  = this->getTeam();

    //Movimientos del caballo


    i = row - 2;
    j = col - 1;
    if(i >=0 && j>=0 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }


    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (juego->collection[i][j]->getPieceColor() != team) ) {
        location.append(juego->collection[i][j]);
        if(location.last()->getHasPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}
