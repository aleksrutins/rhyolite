#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include "entity.h"
#include "system.h"

namespace rh {

class Component : public QObject
{
    Q_OBJECT

    template<typename C>
    auto getComponent() -> C* {
        if(!parent()) return nullptr;
        return ((Entity*)parent())->findChild<C*>();
    }


public:
    Component(Entity *entity);

    virtual auto id() -> QString = 0;
    virtual auto init(System const &) -> bool = 0;
    virtual void update(System const &) = 0;

signals:
};

}

#endif // COMPONENT_H
