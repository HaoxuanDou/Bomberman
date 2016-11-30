#include "Game.h"
#include <QApplication>
#include <memory>
std::unique_ptr<Game> game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = std::unique_ptr<Game>(new Game());
    game->show();

    return a.exec();
}
