#include "bishop.h"
#include "game.h"
extern game * juego;

Bishop::Bishop(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setImage();
    type = "A";
}
void Bishop::setImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/bishopW.png"));
    else
        setPixmap(QPixmap(":/bishopB.png"));
}
void Bishop::resizeImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/bishopWm.png"));
    else
        setPixmap(QPixmap(":/bishopBm.png"));
}

void Bishop::moves()
{
    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getTeam();
    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
       if(juego->collection[i][j]->getPieceColor() == team ) {
           break;

       }
       else
       {
           location.append(juego->collection[i][j]);
           if(boxSetting(location.last()) ){
               break;
           }
       }
    }
      for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
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

       for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
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

        for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
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

}
