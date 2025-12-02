#include <QGuiApplication>

#include <rhyolite/core.h>
#include <rhyolite/2d.h>

class Gradient : public Rh::Component {
    Q_OBJECT
    long long count;
public:
    Gradient(Rh::Entity *e) : Component(e) {}
    QString id();

    void init(Rh::System const*);

    void update(Rh::System const* s);
};


QString Gradient::id() { return "Rhyolite.Example.Gradient"; }

void Gradient::init(Rh::System const*) {}

void Gradient::update(Rh::System const* s) {
    Rh::TwoD::Renderer2D const *r = dynamic_cast<Rh::TwoD::Renderer2D const*>(s);
    if(!r) return;

    r->paint->fillRect(0, 0, r->width(), r->height(), QGradient::NightFade);
    r->paint->drawText(QRectF(0, 0, r->width(), r->height()), Qt::AlignCenter, QString::number(count));
    count++;
    count %= 100;
}

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    auto g = new Rh::Game(&a);

    Rh::TwoD::Renderer2D wnd;

    g->use(&wnd);

    auto bg = new Rh::Entity(g, "background");

    new Gradient(bg);

    wnd.show();

    return a.exec();
}

#include "main.moc"
