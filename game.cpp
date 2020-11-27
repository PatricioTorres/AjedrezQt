#include "game.h"

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
    drawDeadHolder(0,0,Qt::lightGray);
    drawDeadHolder(1100,0,Qt::lightGray);
    chess->drawBoxes(width()/2-400,50);

}
void game::drawDeadHolder(int x, int y,QColor color)
{
    deadHolder = new QGraphicsRectItem(x,y,300,900);
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
