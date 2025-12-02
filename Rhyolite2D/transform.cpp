#include "include/rhyolite/2d/transform.h"
#include <rhyolite/2d/camera.h>
#include <rhyolite/2d/cameraentity.h>

namespace Rh {
namespace TwoD {

QString Transform::id()
{
    return "transform2d";
}

void Transform::init(const System *)
{

}

void Transform::update(const System *)
{

}

QPoint Transform::getScreenPosition()
{
    auto camera = game()->findChild<Camera*>();

    if(!camera) return position;
    else return position - camera->position;
}

} // namespace TwoD
} // namespace Rh
