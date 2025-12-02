#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "scene.h"

namespace Rh {

class System;

class Game : public Scene
{
    Q_OBJECT

    QVector<System*> systems;

public:
    explicit Game(QObject *parent = nullptr);

    void use(System*);

    template<typename S>
    auto getSystem() -> S*
    {
        for (auto s : systems) {
            if(typeid(*s) == typeid(S)) return s;
        }
        return nullptr;
    }
signals:
};

}
#endif // GAME_H
