#include "king.h"
#include "game.h"
extern game * juego;

king::king(QString team,QGraphicsItem *parent):Piece(team,parent)
{
    setImage();
    type = "R";
}

void king::setImage()
{
    if(Team== "WHITE")
        setPixmap(QPixmap(":/kingW.png"));
    else
        setPixmap(QPixmap(":/kingB.png"));
}
void king::resizeImage()
{
    if(Team== "WHITE")
        setPixmap(QPixmap(":/kingWm.png"));
    else
        setPixmap(QPixmap(":/kingBm.png"));
}

void king::moves()
{

    location.clear();
    int row = this->getCurrentBox()->rowLoc;
    int col = this->getCurrentBox()->colLoc;
    QString team = this->getTeam();

        if(col > 0 && row > 0 && !(juego->collection[row-1][col-1]->getPieceColor() == team)) {
            //Mover aarriba izquiera
            location.append(juego->collection[row-1][col-1]);
            juego->collection[row-1][col-1]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col < 7 && row > 0 && !(juego->collection[row-1][col+1]->getPieceColor() == team)) {
            //Mover arriba derecha
            location.append(juego->collection[row-1][col+1]);
            juego->collection[row-1][col+1]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(row>0 && !(juego->collection[row-1][col]->getPieceColor() == team)) {
            //Mover arriba
            location.append(juego->collection[row-1][col]);
            juego->collection[row-1][col]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(row<7 && !(juego->collection[row+1][col]->getPieceColor() == team)) {
            //Mover abajo
            location.append(juego->collection[row+1][col]);
            juego->collection[row+1][col]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col>0 && !(juego->collection[row][col-1]->getPieceColor() == team)) {
            //Mover izquiera
            location.append(juego->collection[row][col-1]);
            juego->collection[row][col-1]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col<7 && !(juego->collection[row][col+1]->getPieceColor() == team)) {
            //Mover derecha
            location.append(juego->collection[row][col+1]);
            juego->collection[row][col+1]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col > 0 && row < 7  && !(juego->collection[row+1][col-1]->getPieceColor() == team)) {
            //Mover abajo izquiera
            location.append(juego->collection[row+1][col-1]);
            juego->collection[row+1][col-1]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }
        if(col < 7 && row < 7 && !(juego->collection[row+1][col+1]->getPieceColor() == team)) {
            //Mover abajo derecha
            location.append(juego->collection[row+1][col+1]);
            juego->collection[row+1][col+1]->setColor(Qt::darkRed);
            if(location.last()->getHasPiece()){
                location.last()->setColor(Qt::red);
            }
        }


            SafeLocation();


}

void king::SafeLocation() {
    QList <Piece *> pList = juego->alivePiece;
    for(size_t i = 0,n = pList.size(); i < n; i++) {

        if(pList[i]->getTeam() != this->getTeam())
        {
            QList <box *> bList = pList[i]->moveLocation();

            for(size_t j = 0, n = bList.size(); j < n; j++) {
                Pawn *c = dynamic_cast<Pawn *> (pList[i]) ;
                if(c)
                    continue;
                for(size_t k = 0, n = location.size(); k < n; k++) {
                   if(bList[j] == location [k]) {
                       location[k]->setColor(Qt::black);
                   }
                }
            }
        }
    }
}
