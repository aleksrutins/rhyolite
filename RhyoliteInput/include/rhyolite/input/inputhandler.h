#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QObject>
#include <QEvent>
#include <QSet>

namespace Rh {
namespace Input {

class InputHandler : public QObject
{
    Q_OBJECT

    QSet<int> keys;
    bool handle(QEvent *event);
public:
    explicit InputHandler(QObject *parent = nullptr);

    inline auto handler() {
        return [&](QEvent *evt){return this->handle(evt);};
    }
    bool isKeyDown(Qt::Key key);
signals:
};

} // namespace Input
} // namespace Rh

#endif // INPUTHANDLER_H
