#include "include/rhyolite/2d/sprite.h"
#include <rhyolite/2d/renderer2d.h>
#include <rhyolite/2d/transform.h>

namespace Rh {
namespace TwoD {

QString Sprite::id()
{
    return "Rhyolite.2D.Sprite";
}

void Sprite::init(const System *)
{

}

void Sprite::update(const System *s)
{
    auto r = dynamic_cast<Renderer2D const*>(s);
    if(!r) return;

    auto tr = getComponent<Transform>();
    if(!tr) return;

    r->paint->drawPicture(tr->position, frames[frame]);

    frame++;
    frame %= frames.length();
}

} // namespace TwoD
} // namespace Rh
