#include "include/rhyolite/scene.h"
#include "include/rhyolite/entity.h"

namespace Rh {

Scene::Scene(QObject *parent)
    : QObject(parent)
{}

auto Scene::entities() -> QVector<Entity*>
{
    QVector<Entity*> res;
    for (auto c : children()) {
        auto e = qobject_cast<Entity*>(c);
        if(e) res.append(e);
        else {
            auto s = qobject_cast<Scene*>(c);
            if(s) res.append(s->entities());
        }
    }

    return res;
}

} // namespace Rh
