#ifndef SPRITE_H
#define SPRITE_H

#include <QPicture>
#include <rhyolite/core.h>

namespace Rh {
namespace TwoD {

class Sprite : public Rh::Component
{
    Q_OBJECT

    QList<QPicture> frames;
    int frame = 0;

public:
    Sprite(Entity *entity) : Component(entity) {}

    QString id();
    void init(System const*);
    void update(System const*);
};

} // namespace TwoD
} // namespace Rh

#endif // SPRITE_H
