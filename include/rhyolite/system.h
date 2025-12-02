#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>


namespace rh {

class Game;

class System : public QObject
{
    Q_OBJECT
public:
    System(Game *);

signals:
};

} // namespace rh

#endif // SYSTEM_H
