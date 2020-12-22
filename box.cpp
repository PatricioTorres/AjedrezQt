#include "box.h"
#include "game.h"
#include <iostream>
#include "king.h"
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

                //asignacion de posicion de la pieza
                 this->currentPiece->setPos(K+xinicial,M+yinicial);

                this->currentPiece->setIsPlaced(true);
                //la pieza a sido capturada


               }

               }
         }


            juego->pieceToMove->getCurrentBox()->setHasPiece(false);
            juego->pieceToMove->getCurrentBox()->currentPiece = NULL;
            juego->pieceToMove->getCurrentBox()->resetOriginalColor();

            movedPiece(juego->pieceToMove, capture);

            juego->pieceToMove = NULL;

            juego->changeTurn();
            VeriCheck();
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
        if(tam>=9)
        {
            delete juego->whiteTable[8];
            delete juego->blackTable[8];
            tam = 8;
        }

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

void box::VeriCheck(){
    int c = 0;
    QList <Piece *> pList = juego->alivePiece;
    for(size_t i = 0,n=pList.size(); i < n; i++ ) {

        king * p = dynamic_cast<king *> (pList[i]);
        if(p){
            continue;
        }
        pList[i]->moves();
        pList[i]->color();
        QList <box *> bList = pList[i]->moveLocation();
        for(size_t j = 0,n = bList.size(); j < n; j ++) {
            king * p = dynamic_cast<king *> (bList[j]->currentPiece);
            if(p) {
                if(p->getTeam() == pList[i]->getTeam())
                    continue;
                bList[j]->setColor(Qt::green);
                pList[i]->getCurrentBox()->setColor(Qt::blue);
                if(!juego->check->isVisible()){
                    juego->check->setVisible(true);
                }
                else{
                    bList[j]->resetOriginalColor();
                    pList[i]->getCurrentBox()->resetOriginalColor();
                    if(juego->getTurn()=="WHITE"){
                        juego->addItem(new QGraphicsPixmapItem((QPixmap(":/WinW.jpg"))));
                    }else
                        juego->addItem(new QGraphicsPixmapItem((QPixmap(":/WinB.png"))));

                }
                c++;

            }
        }


    }
    if(!c){
        juego->check->setVisible(false);
        for(size_t i = 0,n=pList.size(); i < n; i++ )
            pList[i]->getCurrentBox()->resetOriginalColor();
    }

}
