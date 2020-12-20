#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "box.h"
#include "moves.h"
#include <board.h>
#include "piece.h"
class game:public QGraphicsView
{
    Q_OBJECT
public:
    game(QWidget *parent = 0);
    QGraphicsTextItem *check;
    int contadorB=0;
    box * collection[8][8];
    box * captureBlack[5][5];
    box * captureWhite[5][5];
    moves* movimientos[2][2];
    void displayMainMenu();
    void drawBoard();
    void drawDeadHolder(int x, int y, int width, int height, QColor color);
    void addItem(QGraphicsItem *item);
    QString getTurn() ;
    void setTurn( QString value);
    void changeTurn();
    Piece *pieceToMove;
    QList <Piece *> alivePiece;
    board *chess;
    board *captureBox;
    moves *textoDemo;
    QList<QString>* getTableWhite();
    QList<QString>* getTableBlack();
    moves* getWhiteTable();
    moves* getBlackTable();
    moves* whiteTable[6];
    moves* blackTable[6];
    int& getNumberTurn();
    void sumTurn();
    void drawTable();
    void setContadorB(int cont);
    int getContadorB();


private:
    QGraphicsScene *Scene;
    QGraphicsTextItem * turnDisplay;
    int numberTurn = 0;
    moves* titleWhite;
    moves* titleBlack;

    QString turn;
    QGraphicsRectItem * deadHolder;
    QList<QString> tableWhite;
    QList<QString> tableBlack;


};

#endif // GAME_H
