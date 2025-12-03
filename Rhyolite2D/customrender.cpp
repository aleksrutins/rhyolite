#include <rhyolite/2d/customrender.h>

namespace Rh {
namespace TwoD {

QString CustomRender::id()
{
    return "Rhyolite.2D.CustomRender";
}

void CustomRender::init(const System *)
{

}

void CustomRender::update(const System *s)
{
    auto r = dynamic_cast<Renderer2D const*>(s);
    if(!r) return;

    _paint(r);
}

} // namespace TwoD
} // namespace Rh
