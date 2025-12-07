#include "include/rhyolite/timer/timersystem.h"
#include <rhyolite/core.h>

#include <QBasicTimer>

namespace Rh {
namespace Timer {

TimerSystem::TimerSystem(QObject *parent)
    : QObject{parent}
{}

void TimerSystem::start(double fps)
{
    this->fps = fps;
    _timer.start(1000/fps, this);
}

void TimerSystem::timerEvent(QTimerEvent *event)
{
    for(auto e : game->entities()) {
        e->update(this);
    }
}

} // namespace Timer
} // namespace Rh
