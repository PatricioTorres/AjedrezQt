#include "board.h"
#include "game.h"
#include "queen.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "horse.h"
#include "bishop.h"

extern game *juego;
board::board()
{

}
void board::drawBoxes(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            box *caja = new box();
            juego->collection[i][j] = caja;
            caja->rowLoc = i;
            caja->colLoc = j;
            caja->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                caja->setOriginalColor(Qt::white);
            else
                caja->setOriginalColor(Qt::darkGray);
            juego->addItem(caja);


        }
    }

}
void board::drawCaptureBoxes(int x,int y, bool team)
{
    int SHIFT = 60;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
        {
            box *caja = new box();
            if(team)
                //para las piezas negras
                juego->captureBlack[i][j] = caja;
            else
                //para las piezas blancas

                juego->captureWhite[i][j] = caja;
            caja->rowLoc = i;
            caja->colLoc = j;
            caja->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                caja->setOriginalColor(Qt::blue);
            else
                caja->setOriginalColor(Qt::red);
            juego->addItem(caja);


        }
    }

}

void board::drawTables()
{

}

void board::setUpWhite()
{
    Piece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("WHITE");
        white.append(piece);
    }
    piece = new Rook("WHITE");
    white.append(piece);
    piece = new horse("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new Queen("WHITE");
    white.append(piece);
    piece = new king("WHITE");
    white.append(piece);
    piece = new Bishop("WHITE");
    white.append(piece);
    piece = new horse("WHITE");
    white.append(piece);
    piece = new Rook("WHITE");
    white.append(piece);

}

void board::setUpBlack()
{
    Piece *piece;
    piece = new Rook("BLACK");
    black.append(piece);
    piece = new horse("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new Queen("BLACK");
    black.append(piece);
    piece = new king("BLACK");
    black.append(piece);
    piece = new Bishop("BLACK");
    black.append(piece);
    piece = new horse("BLACK");
    black.append(piece);
    piece = new Rook("BLACK");
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("BLACK");
        black.append(piece);
    }
}


void board::addPiece() {
    setUpBlack();
    setUpWhite();
    for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++)
            {

                box *box =juego->collection[i][j];
                if(i < 2) {
                    static int k;
                    box->placePiece(black[k]);
                    juego->alivePiece.append(black[k]);
                    juego->addItem(black[k++]);
                }
                if(i > 5) {
                    static int h;
                    box->placePiece(white[h]);
                    juego->alivePiece.append(white[h]);
                    juego->addItem(white[h++]);
                }

            }
        }
}
