#include "include/rhyolite/component.h"

namespace rh {

Component::Component(Entity *entity)
    : QObject(entity)
{
}

}
