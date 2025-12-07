#ifndef TIMERSYSTEM_H
#define TIMERSYSTEM_H

#include <QObject>
#include <QBasicTimer>
#include <rhyolite/system.h>

namespace Rh {
class Game;

namespace Timer {

class TimerSystem : public QObject, public Rh::System
{
    Q_OBJECT
    Q_INTERFACES(Rh::System)
    Game *game;
    QBasicTimer _timer;
public:
    explicit TimerSystem(QObject *parent = nullptr);

    void init(Game *g) {game = g;}
    void start(double fps = 60);

    double fps;

protected:
    void timerEvent(QTimerEvent *event) override;
};

} // namespace Timer
} // namespace Rh

#endif // TIMERSYSTEM_H
