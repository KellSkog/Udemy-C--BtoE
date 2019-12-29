#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "doOtherStuff.hh"

TEST_CASE("Hello") {
    ch52::Dog<std::string> rufus{"woof"};
    bool equal = (rufus.speak() == "woof");
    CHECK(rufus.speak() == "woof");
    SUBCASE("World") {
        REQUIRE(rufus.speak() == "woof");
    }
}