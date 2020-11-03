#include "mainwindow.h"
#include <QApplication>
#include "game.h"
#include "pawn.h"

game *juego;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    juego = new game();
    juego->show();
    juego->displayMainMenu();

    juego->chess->addPiece();
    return a.exec();
}
