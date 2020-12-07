#include "rook.h"
#include "game.h"
extern game * juego;

Rook::Rook(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setImage();
    type = "T";
}

void Rook::setImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/rookW.png"));
    else
        setPixmap(QPixmap(":/rookB.png"));
}
void Rook::resizeImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/rookWm.png"));
    else
        setPixmap(QPixmap(":/rookBm.png"));
}

void Rook::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getTeam();
    //For up

     for(int i = row-1,j = col; i >= 0 ; i--) {
       if(juego->collection[i][j]->getPieceColor() == team ) {
           break;
       }
       else
       {
           location.append(juego->collection[i][j]);
           if(boxSetting(location.last()))
               break;
        }
    }

     //For Down

      for(int i = row+1,j = col; i <= 7 ; i++) {
        if(juego->collection[i][j]->getPieceColor() == team ) {
            break;
        }
        else
        {
            location.append(juego->collection[i][j]);
            if(boxSetting(location.last())){
                break;
            }
        }
     }

      //For left

       for(int i = row,j = col-1; j >= 0 ; j--) {
         if(juego->collection[i][j]->getPieceColor() == team ) {
             break;
         }
         else
         {
             location.append(juego->collection[i][j]);
             if(boxSetting(location.last()))
                break;
         }
        }
       //For Right

        for(int i = row,j = col+1; j <= 7 ; j++)
        {
              if(juego->collection[i][j]->getPieceColor() == team ) {
                  break;
              }
              else
              {
                  location.append(juego->collection[i][j]);
                  if(boxSetting(location.last()))
                      break;
               }

       }


}

