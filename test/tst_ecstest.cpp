#include <QTest>

// add necessary includes here
#include <rhyolite/core.h>
using namespace Rh;

class ECSTest : public QObject
{
    Q_OBJECT

public:
    ECSTest();
    ~ECSTest();

private slots:
    void test_entity();
};

ECSTest::ECSTest() {}

ECSTest::~ECSTest() {}

void ECSTest::test_entity() {
    auto g = new Game(this);

    auto helloWorld = new Entity(g, "hello");

    Q_ASSERT(g->findChild<Entity*>("hello") == helloWorld);
}

QTEST_APPLESS_MAIN(ECSTest)

#include "tst_ecstest.moc"
