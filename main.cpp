#include <QApplication>
#include "game.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///create a new object game, show it and call its main menu method
    Game* game = new Game();
    game->show();
    game->displayMainMenu();    

    return a.exec();

}
