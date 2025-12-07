#include "include/rhyolite/input/inputhandler.h"

#include <QKeyEvent>

namespace Rh {
namespace Input {

InputHandler::InputHandler(QObject *parent)
    : QObject{parent}
{}

bool InputHandler::handle(QEvent *event)
{
    if(event->type() == QEvent::KeyPress) {
        auto kev = dynamic_cast<QKeyEvent*>(event);
        if(kev && !kev->isAutoRepeat()) {
            keys.insert(kev->key());
        }
        return true;
    } else if(event->type() == QEvent::KeyRelease) {
        auto kev = dynamic_cast<QKeyEvent*>(event);
        if(kev && !kev->isAutoRepeat()) {
            keys.remove(kev->key());
        }
        return true;
    }
    return false;
}

bool InputHandler::isKeyDown(Qt::Key key)
{
    return keys.contains(key);
}

} // namespace Input
} // namespace Rh
