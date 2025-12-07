#ifndef UTIL_H
#define UTIL_H

#include "../../../RhyoliteMath_global.h"

#include <QPointF>

namespace Rh {
namespace Math {

template <typename T>
inline auto lerp(T a, T b, qreal t) -> T {
    return a + t * (b - a);
};

}
}

#endif // UTIL_H
