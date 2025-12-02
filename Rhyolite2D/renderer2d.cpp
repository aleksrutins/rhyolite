#include "include/rhyolite/2d/renderer2d.h"

namespace Rh {
namespace TwoD {

Renderer2D::Renderer2D(QWindow *parent)
    : QWindow(parent)
    , m_backingStore(new QBackingStore(this))
{}

void Renderer2D::exposeEvent(QExposeEvent *)
{
    if (isExposed())
        renderNow();
}

void Renderer2D::resizeEvent(QResizeEvent *resizeEvent)
{
    m_backingStore->resize(resizeEvent->size());
}

void Renderer2D::renderNow()
{
    if (!isExposed())
        return;

    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    //painter.fillRect(0, 0, width(), height(), QColor);
    render(&painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

void Renderer2D::render(QPainter *painter)
{
    paint = painter;
    for(auto e : game->entities()) {
        e->update(this);
    }
    paint = 0;
}

void Renderer2D::init(Game *g)
{
    game = g;
}

void Renderer2D::renderLater()
{
    requestUpdate();
}

bool Renderer2D::event(QEvent *event)
{
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        renderLater();
        return true;
    }
    return QWindow::event(event);
}

} // namespace TwoD
} // namespace Rh
