#ifndef CAMERAENTITY_H
#define CAMERAENTITY_H

#include <QObject>
#include <rhyolite/entity.h>
#include "camera.h"

namespace Rh {
namespace TwoD {

class CameraEntity : public Rh::Entity
{
    Q_OBJECT
public:
    CameraEntity(Game *game, QAnyStringView name = "camera");

    auto camera() -> Camera*;
};

} // namespace TwoD
} // namespace Rh

#endif // CAMERAENTITY_H
