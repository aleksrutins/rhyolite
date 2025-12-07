#include "movabletext.h"
#include <rhyolite/2d.h>
#include <rhyolite/input.h>
#include <rhyolite/math.h>

using namespace Rh;
using namespace Rh::TwoD;
using namespace Rh::Timer;
using namespace Rh::Math;

MovableText::MovableText(Scene *s)
    : Entity(s, "text")
{
    auto t = new Transform(this);
    t->position = QPoint(50, 50);

    new OnTick(this, [&](TimerSystem const*) {
        auto input = s->findChild<Rh::Input::InputHandler*>();
        auto ix = QPointF(10, 0), iy = QPointF(0, 10);
        if(input->isKeyDown(Qt::Key_A))
            t->position = lerp<QPointF>(t->position, t->position - ix, .1).toPoint();
        if(input->isKeyDown(Qt::Key_D))
            t->position = lerp<QPointF>(t->position, t->position + ix, .1).toPoint();
        if(input->isKeyDown(Qt::Key_W))
            t->position = lerp<QPointF>(t->position, t->position - iy, .1).toPoint();
        if(input->isKeyDown(Qt::Key_S))
            t->position = lerp<QPointF>(t->position, t->position + iy, .1).toPoint();

        count += .1;
    });

    new CustomRender(this, [&](Renderer2D const *r) {
        r->paint->drawText(t->getScreenPosition(), QString::number((long)count));
    });
}
