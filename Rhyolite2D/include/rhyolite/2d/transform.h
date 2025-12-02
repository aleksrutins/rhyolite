#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <rhyolite/core.h>
#include <QPoint>

namespace Rh {
namespace TwoD {

class Transform : public Component
{
    Q_OBJECT
public:
    Transform(Entity *e) : Component(e) {}
    QString id();
    void init(System const*);
    void update(System const*);

    QPoint position;
    QPoint getScreenPosition();

signals:
};

} // namespace TwoD
} // namespace Rh

#endif // TRANSFORM_H
