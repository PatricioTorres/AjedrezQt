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

             //if(juego->pieceToMove->getBox()->getPieceColor()==  "WHITE" )


             juego->pieceToMove->firstMove = false;
            bool capture = false;

            if(this->getHasPiece()){

                this->currentPiece->resizeImage();
                 this->currentPiece->setIsPlaced(false);
               if(this->currentPiece->getTeam()=="WHITE"){
                    this->currentPiece->resizeImage();

                  if(!(this->currentPiece->getIsPlaced())){
                int col=5;

               int i=0,j=0;
                //posicion x inicial de la pieza
                int xInicial=20;
                //posicion y inicial de la pieza
                int yInicial=60;
                 int t=juego->getContadorB();

                i=(t%col)*60;
                j=(t/col)*60;
                 //juego->captureBlack[i][j]->capturePiece(this->currentPiece);
                //asignacion de posicion de la pieza
                 this->currentPiece->setPos(i+xInicial,j+yInicial);

                // this->currentPiece->~Piece();



                this->currentPiece->setIsPlaced(true);
                //la pieza a sido capturada


               }

               }

               if(this->currentPiece->getTeam()=="BLACK"){
                    this->currentPiece->resizeImage();

                  if(!(this->currentPiece->getIsPlaced())){
                int col=5;

               int K=0,M=0;
                //posicion x inicial de la pieza
                int xinicial=20;
                //posicion y inicial de la pieza
                int yinicial=560;
                 int v=juego->getContadorW();

                K=(v%col)*60;
                M=(v/col)*60;
                 //juego->captureBlack[i][j]->capturePiece(this->currentPiece);
                //asignacion de posicion de la pieza
                 this->currentPiece->setPos(K+xinicial,M+yinicial);

                // this->currentPiece->~Piece();



                this->currentPiece->setIsPlaced(true);
                //la pieza a sido capturada


               }

               }
               //las fichas cambian de tamaño para mandarlas a la otra tabla
                //las blancas en 0,0

                  //      juego->captureWhite[1][1]->capturePiece(this->currentPiece);
                    //juego->captureWhite[1][2]->capturePiece(this->currentPiece);
                    //juego->captureWhite[1][3]->capturePiece(this->currentPiece);

               //las negras se guardan en 0,2
               //si la siguiente pieza a mover es blanca se guarda en [0][2]
               /* if(this->currentPiece->getTeam()=="BLACK"){

                     for(int i=0;i<5;i++){
                         for(int j=0;j<5;j++){
                             if(capture==false){
                    juego->captureBlack[i][j]->capturePiece(this->currentPiece);


                               capture=true;
                             }

                    juego->captureBlack[0][2]->getHasPiece();}}
                 }
                */

                //capture = true;
}

              //juego->placeInDeadPlace(this->currentPiece);
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
        move += piece->getType();
    }
    if(capture)
    {
        move += "x";
    }
    char col = colLoc + 97;
    char row = 56 - rowLoc;
    move += col+separator+row;
    if(juego->getTurn() == "WHITE")
    {
        juego->getTableWhite()->insert(juego->getTableWhite()->length(), move);
        int tam = juego->getNumberTurn();
        if(tam>=6)
        {
            delete juego->whiteTable[5];
            delete juego->blackTable[5];
            tam = 5;
        }

        QString textW, textB;
        for(int i = tam; i>0; i--)
        {
            juego->whiteTable[i] = juego->whiteTable[i-1];
            juego->blackTable[i] = juego->blackTable[i-1];
            juego->whiteTable[i]->rePos(1151, 75+50*i);
            juego->blackTable[i]->rePos(1301, 75+50*i);
        }
        juego->whiteTable[0] = new moves(1151, 75, move, Qt::white);
        juego->sumTurn();
    }
    else
    {
        juego->getTableBlack()->insert(juego->getTableBlack()->length(), move);
        juego->blackTable[0] = new moves(1301, 75, move, Qt::black);
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

