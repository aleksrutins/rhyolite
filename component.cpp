#include "include/rhyolite/component.h"

namespace Rh {

auto Component::game() -> Game *
{
    if(!parent()) return nullptr;

    return (Game*)parent()->parent();
}

}
