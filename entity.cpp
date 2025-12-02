#include "include/rhyolite/entity.h"

#include "include/rhyolite/game.h"

namespace rh {

Entity::Entity(Game *parent, QAnyStringView name)
    : QObject(parent)
{
    setObjectName(name);
}

} // namespace rh
