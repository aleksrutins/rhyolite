#include "include/rhyolite/system.h"

#include "include/rhyolite/game.h"

namespace rh {

System::System(Game *parent)
    : QObject{parent}
{}

} // namespace rh
