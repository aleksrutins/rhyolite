#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include "entity.h"
#include "system.h"

namespace Rh {

class Component
{
    template<typename C>
    auto getComponent() -> C* {
        auto obj = reinterpret_cast<QObject*>(this);
        if(!obj->parent()) return nullptr;
        return ((Entity*)obj->parent())->findChild<C*>();
    }


public:
    virtual auto id() -> QString = 0;
    virtual void init(System const*) = 0;
    virtual void update(System const*) = 0;
};

}

Q_DECLARE_INTERFACE(Rh::Component, "Rhyolite/Component")

#endif // COMPONENT_H
