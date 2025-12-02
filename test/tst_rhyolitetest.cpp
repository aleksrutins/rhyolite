#include <catch2/catch_test_macros.hpp>
#include <rhyolite/core.h>
using namespace Rh;

TEST_CASE("ECS Test", "[fancy]")
{
    auto g = new Game();

    auto helloWorld = new Entity(g, "hello");

    REQUIRE(g->findChild<Entity*>("hello") == helloWorld);

    delete g;
}
