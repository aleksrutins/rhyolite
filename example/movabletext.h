#ifndef MOVABLETEXT_H
#define MOVABLETEXT_H

#include <QObject>
#include <rhyolite/core.h>

class MovableText : public Rh::Entity
{
    Q_OBJECT
    double count = 0;
public:
    MovableText(Rh::Scene *s);
};

#endif // MOVABLETEXT_H
