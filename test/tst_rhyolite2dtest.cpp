#include <catch2/catch_test_macros.hpp>
#include <rhyolite/core.h>
#include <rhyolite/2d.h>
using namespace Rh;
using namespace Rh::TwoD;

TEST_CASE("2D Tests", "[2d]")
{
    auto g = new Game();
    auto player = new Entity(g, "player");
    auto trf = new Transform(player);

    new CameraEntity(g);

    SECTION("transform")
    {
        trf->position = QPoint(0, 0);

        REQUIRE(trf->getScreenPosition() == QPoint(0, 0));
    }

    SECTION("camera")
    {

        g->findChild<Camera*>()->position += QPoint(1, 1);

        REQUIRE(trf->getScreenPosition() == QPoint(-1, -1));
    }

    delete g;
}
