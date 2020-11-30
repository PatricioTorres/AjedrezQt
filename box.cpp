#include "box.h"
#include "game.h"
#include <iostream>

extern game *juego;
box::box(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,100,100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setHasPiece(false);
    setPieceColor("NONE");
    currentPiece = NULL;
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
void box::resetOriginalColor()
{
    setColor(originalColor);
}

void box::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

        if(currentPiece == juego->pieceToMove && currentPiece){

            currentPiece->mousePressEvent(event);
            return;
        }


        if(juego->pieceToMove){

            if(this->getPieceColor() == juego->pieceToMove->getTeam())
                return;

            QList <box *> movLoc = juego->pieceToMove->moveLocation();

            int check = 0;
            for(size_t i = 0, n = movLoc.size(); i < n;i++) {
                if(movLoc[i] == this) {
                    check++;

                }
            }

            if(check == 0)
                return;

             juego->pieceToMove->color();

             juego->pieceToMove->firstMove = false;
            bool capture = false;
            if(this->getHasPiece()){
                this->currentPiece->setIsPlaced(false);
                this->currentPiece->setCurrentBox(NULL);
                //juego->placeInDeadPlace(this->currentPiece);
                capture = true;
            }

            juego->pieceToMove->getCurrentBox()->setHasPiece(false);
            juego->pieceToMove->getCurrentBox()->currentPiece = NULL;
            juego->pieceToMove->getCurrentBox()->resetOriginalColor();
            movedPiece(juego->pieceToMove, capture);

            juego->pieceToMove = NULL;

            juego->changeTurn();
            //checkForCheck();
        }

        else if(this->getHasPiece())
        {
            this->currentPiece->mousePressEvent(event);
        }
}
box::~box()
{
    delete this;
}
void box::setPieceColor(QString value)
{
    PieceColor = value;
}

QString box::getPieceColor()
{
    return PieceColor;
}

bool box::getHasPiece()
{
    return hasPiece;
}

void box::placePiece(Piece *piece)
{
    piece->setPos(x()+50- piece->pixmap().width()/2  ,y()+50-piece->pixmap().width()/2);
    piece->setCurrentBox(this);
    setHasPiece(true,piece);
    currentPiece = piece;
}
void box::movedPiece(Piece *piece, bool& capture)
{
    placePiece(piece);
    if(piece->getType() != "P")
    {
        std::cout<<piece->getType().toStdString();
    }
    if(capture)
    {
        std::cout<<"x";
    }
    char col = colLoc + 97;
    int row = 8 - rowLoc;
    std::cout<<col<<row;
    if(juego->getTurn() == "WHITE")
    {
        std::cout<<"\t";
    }
    else
    {
        std::cout<<std::endl;
    }
}
void box::setHasPiece(bool value, Piece *piece)
{
    hasPiece = value;
    if(value)
        setPieceColor(piece->getTeam());
    else
        setPieceColor("NONE");
}

void Piece::color()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
         location[i]->resetOriginalColor();
    }
}

