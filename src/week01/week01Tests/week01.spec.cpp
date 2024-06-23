#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../week01.hpp"
#include <doctest/doctest.h>

//  1. Typing Game
//  Create a function that takes in two arrays: the array of user-typed words,
// and the array of correctly-typed words and outputs an array containing 1s
// (correctly-typed words) and -1s (incorrectly-typed words).
TEST_CASE("Test1") {
    std::cout << "Test: Testing CorrectStream" << std::endl;
    REQUIRE_EQ(correctStream({"it", "is", "find"}, {"it", "is", "fine"}),
               std::vector<int>{1, 1, -1});
    REQUIRE_EQ(correctStream({"april", "showrs", "bring", "may", "flowers"},
                             {"april", "showers", "bring", "may", "flowers"}),
               std::vector<int>{1, -1, 1, 1, 1});
    REQUIRE_EQ(correctStream({"weird", "indicr", "moment"}, {"weird", "indict", "moment"}),
               std::vector<int>{1, -1, 1});
    REQUIRE_EQ(correctStream({"starry", "wind", "skies"}, {"starry", "wind", "skies"}),
               std::vector<int>{1, 1, 1});
}

TEST_CASE("Test2") {
    std::cout << "Test: Testing negate" << std::endl;

    REQUIRE_EQ(negate({1, 2, 3, 4}), std::vector<int>{-1, -2, -3, -4});
    REQUIRE_EQ(negate({-1, -2, -3, -4}), std::vector<int>{1, 2, 3, 4});
    REQUIRE_EQ(negate(std::vector<int>{}), std::vector<int>{});
}

TEST_CASE("Test3") {
    std::cout << "Test: Testing existHigher" << std::endl;
    REQUIRE(existsHigher({5, 3, 15, 22, 4}, 10));
    REQUIRE(existsHigher({5, 3, 15, 22, 4}, 20));
    REQUIRE_FALSE(existsHigher({4, 3, 3, 3, 2, 2, 2}, 4));
    REQUIRE_FALSE(existsHigher({1, 2, 3, 4, 5}, 8));
    REQUIRE_FALSE(existsHigher(std::vector<int>{}, 5));
}

TEST_CASE("Test4") {
    std::cout << "Test: Testing addEnding" << std::endl;
    REQUIRE_EQ(addEnding({"clever", "meek", "hurried", "nice"}, "ly"),
               std::vector<std::string>{"cleverly", "meekly", "hurriedly", "nicely"});
    REQUIRE_EQ(addEnding({"new", "pander", "scoop"}, "er"),
               std::vector<std::string>{"newer", "panderer", "scooper"});
    REQUIRE_EQ(addEnding({"bend", "sharpen", "mean"}, "ing"),
               std::vector<std::string>{"bending", "sharpening", "meaning"});
    REQUIRE_EQ(addEnding({"bend", "tooth", "mint"}, "y"),
               std::vector<std::string>{"bendy", "toothy", "minty"});
    REQUIRE_EQ(addEnding({"bend", "tooth", "mint"}, "ier"),
               std::vector<std::string>{"bendier", "toothier", "mintier"});
}

TEST_CASE("Test5") {
    std::cout << "Test: Testing differenceMaxMin" << std::endl;
    REQUIRE_EQ(differenceMaxMin({10, 4, 1, 2, 8, 91}), 90);
    REQUIRE_EQ(differenceMaxMin({-70, 43, 34, 54, 22}), 124);
    REQUIRE_EQ(differenceMaxMin({1}), 0);
}
