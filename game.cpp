#include "game.h"
#include <iostream>

game::game(QWidget *parent ):QGraphicsView(parent){
    Scene = new QGraphicsScene();
    Scene->setSceneRect(0,0,1400,1000);

    setFixedSize(1400,970);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Scene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    pieceToMove = NULL;
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100,10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");

        //display Check
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
    setTurn("WHITE");

}
void game::drawBoard()
{
    chess = new board();
    captureBox = new board();
    drawDeadHolder(0,350,300, 200, Qt::lightGray);
    drawDeadHolder(0,850,300, 50, Qt::lightGray);
    drawDeadHolder(1100,0, 300, 900, Qt::lightGray);
    chess->drawCaptureBoxes(0,50, true);
    chess->drawCaptureBoxes(0,550, false);
    chess->drawBoxes(width()/2 -400,50);
    std::cout<<width()<<std::endl;


}
void game::drawDeadHolder(int x, int y,int width, int height,QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addItem(deadHolder);
}
void game::addItem(QGraphicsItem *item)
{
    Scene->addItem(item);
}
void game::displayMainMenu()
{
    drawBoard();
    chess->addPiece();

}
QString game::getTurn()
{
    return turn;
}

void game::setTurn(QString value)
{
    turn = value;
}

void game::changeTurn()
{
    if(getTurn() == "WHITE")
        setTurn("BLACK");
    else
        setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + getTurn());
}
