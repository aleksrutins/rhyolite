#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>


namespace Rh {

class Game;

class System
{
public:
    virtual void init(Game *) = 0;
};

} // namespace Rh

Q_DECLARE_INTERFACE(Rh::System, "Rhyolite.System")

#endif // SYSTEM_H
