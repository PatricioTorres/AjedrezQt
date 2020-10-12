#include "board.h"
#include "game.h"

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
                caja->setOriginalColor(Qt::lightGray);
            else
                caja->setOriginalColor(Qt::darkGray);
            juego->addItem(caja);



        }
    }

}
