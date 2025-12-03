#include "include/rhyolite/2d/background.h"
#include "include/rhyolite/2d/renderer2d.h"

namespace Rh {
namespace TwoD {

QString Background::id()
{
    return "Rhyolite.2D.Background";
}

void Background::init(const System *)
{

}

void Background::update(const System *s)
{
    auto r = dynamic_cast<Renderer2D const*>(s);
    if(!r) return;

    fill(r->width(), r->height(), r->paint);
}

} // namespace TwoD

} // namespace Rh
