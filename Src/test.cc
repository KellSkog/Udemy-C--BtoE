#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "doStuff.hh"

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