#ifndef GAME_H
#define GAME_H

#include <QObject>

namespace rh {

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = nullptr);

signals:
};

}
#endif // GAME_H
