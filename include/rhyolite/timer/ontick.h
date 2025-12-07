#ifndef ONTICK_H
#define ONTICK_H

#include <QObject>
#include <functional>
#include <rhyolite/component.h>

namespace Rh {
namespace Timer {
class TimerSystem;

class OnTick : public Rh::Component
{
    Q_OBJECT
    std::function<void(TimerSystem const*)> _onTick;
public:
    OnTick(Entity *e, decltype(_onTick) onTick) : Component(e), _onTick(onTick) {}

    QString id();
    void init(System const*);
    void update(System const*);
};

} // namespace Timer
} // namespace Rh

#endif // ONTICK_H
