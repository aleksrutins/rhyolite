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

    auto text = new Rh::Entity(g, "text");
    auto t = new Transform(text);
    t->position = QPoint(50, 50);
    new CustomRender(text, [&](Renderer2D const *r) {
        r->paint->drawText(t->getScreenPosition(), QString::number(count));
        count++;
        count %= 400;
    });

    wnd.handle([&](QEvent *evt) {
        if(evt->type() == QEvent::KeyPress) {
            switch(dynamic_cast<QKeyEvent*>(evt)->key()) {
            case Qt::Key_Left:
                t->position -= QPoint(10, 0);
                return true;
            case Qt::Key_Right:
                t->position += QPoint(10, 0);
                return true;
            case Qt::Key_Up:
                t->position -= QPoint(0, 10);
                return true;
            case Qt::Key_Down:
                t->position += QPoint(0, 10);
                return true;
            case Qt::Key_Q:
                return wnd.close();
            }
        }
        return false;
    });

    wnd.show();

    return a.exec();
}
