#ifndef SCENE_H
#define SCENE_H

#include <QObject>

namespace Rh {

class Game;
class Entity;

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent);
    auto entities() -> QVector<Entity*>;
};

} // namespace Rh

#endif // SCENE_H
