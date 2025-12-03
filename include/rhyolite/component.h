#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include "entity.h"
#include "system.h"

namespace Rh {

class Component : public QObject
{
    Q_OBJECT

protected:
    auto game() -> Game*;

    template<typename C>
    auto getComponent() -> C* {
        auto obj = reinterpret_cast<QObject*>(this);
        if(!obj->parent()) return nullptr;
        return ((Entity*)obj->parent())->findChild<C*>();
    }

public:
    Component(Entity *parent) : QObject(parent) {}

    virtual auto id() -> QString = 0;
    virtual void init(System const*) = 0;
    virtual void update(System const*) = 0;
};

}

#endif // COMPONENT_H
