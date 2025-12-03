#ifndef CUSTOMRENDER_H
#define CUSTOMRENDER_H

#include <QObject>
#include <rhyolite/core.h>
#include <rhyolite/2d/renderer2d.h>

namespace Rh {
namespace TwoD {

class CustomRender : public Rh::Component
{
    Q_OBJECT

    std::function<void(Renderer2D const*)> _paint;
public:
    CustomRender(Entity *entity, decltype(_paint) paint)
        : Component(entity)
        , _paint(paint)
    {}

    QString id();
    void init(System const*);
    void update(System const*);
};

} // namespace TwoD
} // namespace Rh

#endif // CUSTOMRENDER_H
