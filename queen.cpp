#include "queen.h"
#include "game.h"
extern game * juego;

Queen::Queen(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setImage();
    type = "D";
}
void Queen::setImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/queenW.png"));
    else
        setPixmap(QPixmap(":/queenB.png"));
}
void Queen::resizeImage()
{
    if(Team == "WHITE")
        setPixmap(QPixmap(":/queenWm.png"));
    else
        setPixmap(QPixmap(":/queenBm.png"));
}
void Queen::moves()
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

        //For upper Left

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

         //For upper right

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

          //For downward right

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

           //For downward left

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
