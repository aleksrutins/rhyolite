#include "include/rhyolite/game.h"
#include "include/rhyolite/system.h"

namespace Rh {

Game::Game(QObject *parent)
    : Scene{parent}
{}

void Game::use(System *s)
{
    systems.append(s);
    s->init(this);
}

}
