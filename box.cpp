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
            if(juego->pieceToMove->getBox()->getPieceColor()==  "WHITE" )


             juego->pieceToMove->firstMove = false;
            bool capture = false;
            if(this->getHasPiece()){
                //this->currentPiece->setIsPlaced(false);

               this->currentPiece->resizeImage();
                //las blancas en 0,1
               juego->captureBlack[0][0]->capturePiece(this->currentPiece);
               //las negras se guardan en 0,2
               if(juego->pieceToMove->getBox()->getPieceColor()==  "WHITE" ){

               juego->captureBlack[0][2]->capturePiece(this->currentPiece);}
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
void box::capturePiece(Piece *piece)
{
    piece->setPos(x()+30- piece->pixmap().width()/2  ,y()+30-piece->pixmap().width()/2);
    piece->setCurrentBox(juego->captureBlack[0][0]);
    juego->captureBlack[0][0]->setHasPiece(true,piece);
    juego->captureBlack[0][0]->currentPiece = piece;
}
void box::movedPiece(Piece *piece, bool& capture)
{
    QString move{""};
    QString separator{""};
    placePiece(piece);
    if(piece->getType() != "P")
    {
        std::cout<<piece->getType().toStdString();
        move += piece->getType();
    }
    if(capture)
    {
        std::cout<<"x";
        move += "x";
    }
    char col = colLoc + 97;
    char row = 56 - rowLoc;
    std::cout<<col<<row;
    move += col+separator+row;
    std::cout<<move.toStdString();
    if(juego->getTurn() == "WHITE")
    {
        juego->getTableWhite()->insert(juego->getTableWhite()->length(), move);
        std::cout<<"\t";
    }
    else
    {
        juego->getTableBlack()->insert(juego->getTableBlack()->length(), move);
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

