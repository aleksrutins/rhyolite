#include "include/rhyolite/entity.h"

#include "include/rhyolite/game.h"
#include "include/rhyolite/component.h"

namespace Rh {

Entity::Entity(Game *parent, QAnyStringView name)
    : QObject(parent)
{
    setObjectName(name);
}

void Entity::init(System *s)
{
    for (auto c : children()) {
        Component *cp = qobject_cast<Component*>(c);
        if(cp) cp->init(s);
    }
}

void Entity::update(System *s)
{
    for (auto c : children()) {
        Component *cp = qobject_cast<Component*>(c);
        if(cp) cp->update(s);
    }
}

} // namespace Rh
