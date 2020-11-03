#include "board.h"
#include "game.h"
#include "pawn.h"
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
void board::addPiece() {
    //for(int i = 0; i < 1; i++) {
    //    for(int j = 0; j < 1; j++)
    //    {

            box *box =juego->collection[7][7];
     //       if(i < 2) {
        //        static int k;
       //         box->placePiece(black[k]);
       //         juego->alivePiece.append(black[k]);
                //juego->addItem(black[k++]);
      //      }
       //     if(i > 5) {
                static int h;
               white.append(new Pawn("WHITE"));
               box->placePiece(white[h]);
               juego->alivePiece.append(white[h]);
                juego->addItem(white[h]);
//            }

  //      }
    //}
}
