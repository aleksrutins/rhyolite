#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "../../../Rhyolite2D_global.h"

#include <rhyolite/core.h>
#include <functional>

#include <QObject>
#include <QWindow>
#include <QBackingStore>
#include <QPainter>
#include <QResizeEvent>

namespace Rh {
namespace TwoD {

class RHYOLITE2D_EXPORT Renderer2D : public QWindow, public Rh::System
{
    Q_OBJECT
    Q_INTERFACES(Rh::System)
    std::function<bool(QEvent*)> customHandler;
    Game *game;
public:
    explicit Renderer2D(QWindow *parent = nullptr);

    virtual void render(QPainter *painter);

    void init(Game *g);

    void handle(decltype(customHandler) handler) {
        customHandler = handler;
    }

    QPainter *paint;

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    QScopedPointer<QBackingStore> m_backingStore;
};

} // namespace TwoD
} // namespace Rh

#endif // RENDERER2D_H
