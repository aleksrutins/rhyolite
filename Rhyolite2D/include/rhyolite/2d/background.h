#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGradient>
#include <QPainter>
#include <functional>
#include <rhyolite/core.h>
#include <rhyolite/2d/transform.h>

template <typename T>
concept Fillable = requires(T a, QPainter *p, int x, int y, int w, int h)
{
    {p->fillRect(x, y, w, h, a)};
};

namespace Rh {
namespace TwoD {

class Background : public Rh::Component
{
    Q_OBJECT

    std::function<void(int, int, QPainter*)> fill;

public:
    template <Fillable B>
    static auto entity(Scene *s, B bg, QAnyStringView name = "background") -> Entity* {
        auto e = new Entity(s, name);
        new Background(e, bg);
        return e;
    }

    template <Fillable B>
    Background(Entity *entity, B bg)
        : Component(entity)
        , fill([bg](int w, int h, QPainter *painter) {painter->fillRect(0, 0, w, h, bg);})
    {}

    QString id();
    void init(System const*);
    void update(System const*);
};

} // namespace TwoD
} // namespace Rh

#endif // BACKGROUND_H
