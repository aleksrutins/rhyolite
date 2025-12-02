#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QPoint>
#include <rhyolite/core.h>

namespace Rh {
namespace TwoD {

class Camera : public Component
{
    Q_OBJECT
public:
    Camera(Entity *e) : Component(e) {}
    QString id();
    void init(System const*);
    void update(System const*);

    QPoint position = QPoint(0, 0);
signals:
};

} // namespace TwoD
} // namespace Rh

#endif // CAMERA_H
