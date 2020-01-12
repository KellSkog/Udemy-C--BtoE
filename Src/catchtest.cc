#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <cmath>
#include "catch.hpp"
#include "doStuff.hh"
#include "doOtherStuff.hh"

TEST_CASE( "TEST_CASE 1" ) {
    Thing<int> num{42};

    REQUIRE( (num == 42) );

    SECTION( "SECTION 1" ) {
        num = 666;
        REQUIRE( (num == 666) );
    }
    SECTION( "SECTION 2" ) {
        num += Thing<int>(8);
        REQUIRE( (num == 50) );
    }
}
TEST_CASE( "OtherStuff 1" ) {
    using namespace other;
    Other<int> one{0};
    Other<int> anOther{0};
    bool equal = (anOther == one);
    REQUIRE( equal );
}
TEST_CASE("Point") {
    using namespace chapter51;
    chapter51::Point<int> thisPoint;
    chapter51::Point<int> thatPoint{42};

    REQUIRE( thisPoint.getX() != thatPoint.getX() );

    SECTION( "SECTION 1" ) {
        /*undefined reference to:
        * int chapter51::operation<int>(chapter51::Point<int>&)
        * Problem was .hh declaration of operateOn did not take const
        * */
        REQUIRE(operateOn(thatPoint) == thatPoint.getX());
    }
    SECTION( "SECTION 2" ) {
        chapter51::Point2D<int> thePoint{42, 666};
        REQUIRE(thePoint.getX() == 42);
        REQUIRE(thePoint.getY() == 666);
    }
    SECTION( "SECTION 3" ) {
        Point2D<int> thePoint{42, 666};
        thePoint.setX(99);
        thePoint.setY(101);
        REQUIRE(thePoint.getX() == 99);
        REQUIRE(thePoint.getY() == 101);
        thePoint.setXY(3, 14);
        REQUIRE(thePoint.getX() == 3);
        REQUIRE(thePoint.getY() == 14);
    }
    SECTION( "Point2D" ) {
        Point2D<double> thePoint{42, 666};
        thePoint.setX(99);
        thePoint.setY(101);
        REQUIRE(thePoint.getX() == 99);
        REQUIRE(thePoint.getY() == 101);
        thePoint.setXY(3.14, 1.41);
        REQUIRE(std::abs(thePoint.getX() - 3.14) < 0.01);
        REQUIRE(std::abs(thePoint.getY() == 14) < 0.01);
    }
    SECTION( "Point3D" ) {
        Point3D<int> thePoint{42, 666, 1963};
        thePoint.setX(99);
        thePoint.setY(101);
        thePoint.setZ(127);
        REQUIRE(thePoint.getX() == 99);
        REQUIRE(thePoint.getY() == 101);
        REQUIRE(thePoint.getZ() == 127);

    }
}
TEST_CASE("Ch52") {
    using namespace ch52;
    SECTION("Animal") {

    }
    SECTION("Dog") {
        Dog<std::string> rufus{"woof"};
        bool equal = (rufus.speak() == "woof");
        CHECK(rufus.speak() == "woof");
        REQUIRE(rufus.speak() == "woof");
    }
    SECTION("Cat") {
        Dog<std::string> nefertite{"mjau"};
        REQUIRE(nefertite.speak() == "mjau");
    }
    SECTION("Dog") {
        Cow<std::string> rosa{"muuu"};
        REQUIRE(rosa.speak() == "muuu");
    }
}