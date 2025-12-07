#include <QGuiApplication>

#include <rhyolite/core.h>
#include <rhyolite/2d.h>
#include <rhyolite/input.h>
#include <rhyolite/math.h>

#include "movabletext.h"

using namespace Rh;
using namespace Rh::TwoD;
using namespace Rh::Math;
using namespace Rh::Timer;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    auto g = new Rh::Game(&a);

    using namespace Rh::TwoD;

    Rh::TwoD::Renderer2D wnd;
    TimerSystem time;

    g->use(&wnd);
    g->use(&time);

    Background::entity(g, QGradient::NightFade);

    double count = 0;

    auto text = new MovableText(g);


    auto input = new Rh::Input::InputHandler(g);

    auto ctr = new Entity(g, "center");
    auto ctrt = new Transform(ctr);
    ctrt->position = QPoint(0, 0);
    new CustomRender(ctr, [&](Renderer2D const *r) {
        r->paint->drawPoint(ctrt->getScreenPosition());
    });

    new CameraEntity(g);

    wnd.handle(input->handler());

    time.start();
    wnd.show();

    return a.exec();
}
