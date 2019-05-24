//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <cstring>
#include "dsstring.h"


TEST_CASE("String class", "[string]"){

    DSString s[10];
    s[0] = DSString("testString");
    s[1] = DSString("a test string");
    s[2] = DSString("");
    s[3] = DSString("THIS IS AN UPPERCASE STRING");
    s[4] = DSString("this is an uppercase string");
    s[5] = DSString("\n");
    s[6] = DSString("");
    s[7] = DSString("  split  split  split  ");
    s[8] = DSString("                          ");
    s[9] = DSString("testString");

    SECTION("Length function"){
        REQUIRE(s[0].getLength() == 10);
        REQUIRE(s[1].getLength() == 13);
        REQUIRE(s[2].getLength() == 0);
        REQUIRE(s[3].getLength() == 27);
    }

    SECTION("Contains function"){
        REQUIRE(s[1].contains("test") == true);
        REQUIRE(s[9].contains("hello") == false);
    }

    SECTION("Get data"){
        REQUIRE((s[1] < s[3]) == false);
        REQUIRE((s[3] < s[6]) == true);
    }

    SECTION("Overloaded assignment operator"){
        s[9] = s[0];
        REQUIRE(s[9].getLength() == 10);
    }
}
