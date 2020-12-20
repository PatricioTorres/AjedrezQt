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
    brush.setColor(Qt::gray);
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
    drawDeadHolder(0,0,300, 50, Qt::lightGray);
    drawDeadHolder(0,850,300, 50, Qt::lightGray);
    drawDeadHolder(1100,0, 300, 900, Qt::lightGray);
    drawTable();

    chess->drawCaptureBoxes(0,50, true);
    chess->drawCaptureBoxes(0,550, false);
    chess->drawBoxes(width()/2 -400,50);
    //QString n = "hola";
    //textoDemo = new moves(1150, 50, n);
    chess->drawTables();
    std::cout<<width()<<std::endl;


}

void game::drawTable()
{
    int y = 1;
    for(int i = 0; i <7; i++, y+=50)
    {
        drawDeadHolder(1102,y, 146, 48, Qt::black);
        drawDeadHolder(1252,y, 146, 48, Qt::white);
    }
    QString w = "WHITE";
    titleWhite = new moves(1151, 25, w);
    QBrush brushW;
    brushW.setStyle(Qt::SolidPattern);
    brushW.setColor(Qt::white);
    titleWhite->setBrush(brushW);

    QString b = "BLACK";
    titleWhite = new moves(1301, 25, b);
    QBrush brushB;
    brushB.setStyle(Qt::SolidPattern);
    brushB.setColor(Qt::black);
    titleWhite->setBrush(brushB);
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

int& game::getNumberTurn()
{
    return numberTurn;
}

void game::sumTurn()
{
    numberTurn++;
}

QList<QString>* game::getTableWhite()
{
    return &tableWhite;
}

QList<QString>* game::getTableBlack()
{
    return &tableBlack;
}

moves* game::getWhiteTable()
{
    return *whiteTable;
}
moves* game::getBlackTable()
{
    return *blackTable;
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
void game::setContadorB(int cont){
    contadorB=cont;
}
int game::getContadorB(){
    return contadorB++;
}
