#include "include/rhyolite/2d/cameraentity.h"

namespace Rh {
namespace TwoD {

CameraEntity::CameraEntity(Game *game, QAnyStringView name)
    : Entity(game, name)
{
    new Camera(this);
}

auto CameraEntity::camera() -> Camera*
{
    return findChild<Camera*>();
}

} // namespace TwoD
} // namespace Rh
