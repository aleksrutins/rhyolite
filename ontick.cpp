#include "include/rhyolite/timer/ontick.h"
#include <rhyolite/timer/timersystem.h>

namespace Rh {
namespace Timer {

QString OnTick::id()
{
    return "Rhyolite.Timer.OnTick";
}

void OnTick::init(const System *)
{}

void OnTick::update(const System *s)
{
    auto t = dynamic_cast<TimerSystem const*>(s);
    if(!t) return;

    _onTick(t);
}

} // namespace Timer
} // namespace Rh
