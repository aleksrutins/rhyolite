#include <QGuiApplication>

#include <rhyolite/core.h>
#include <rhyolite/2d.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    auto g = new Rh::Game(&a);

    using namespace Rh::TwoD;

    Rh::TwoD::Renderer2D wnd;

    g->use(&wnd);

    Background::entity(g, QGradient::NightFade);

    int count = 0;

    new CustomRender(new Rh::Entity(g, "text"), [&](Renderer2D const *r) {
        r->paint->drawText(QRectF(0, 0, r->width(), r->height()), Qt::AlignCenter, QString::number(count));
        count++;
        count %= 100;
    });

    wnd.show();

    return a.exec();
}
