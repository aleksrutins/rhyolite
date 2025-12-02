#ifndef ENTITY_H
#define ENTITY_H

#include <typeinfo>
#include <QObject>

namespace rh {

class Component;
class Game;
class System;

class Entity : public QObject
{
    Q_OBJECT

    QVector<Component*> components;

public:
    Entity(Game *, QAnyStringView);

    void init(System &);
    void update(System &);

signals:
};

} // namespace rh

#endif // ENTITY_H
