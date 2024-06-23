#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../week02.hpp"
#include <doctest/doctest.h>

TEST_CASE("Test6") {
    REQUIRE(findIndex({"abc", "ghj", "banana", "grape"}, "grape") == 3);
    REQUIRE(findIndex({"a", "b", "c", "d", "e", "f"}, "f") == 5);
    REQUIRE(findIndex({"hi", "edabit.com", "testcase", "validstring"}, "edabit.com") == 1);
}


TEST_CASE("Test7") {
    REQUIRE(divisible({4, 4, 4, 4}));
    REQUIRE(divisible({4, 2, 6}));
    REQUIRE(divisible({10, 5, 10}));
    REQUIRE_FALSE(divisible({3, 2, 4, 1}));
    REQUIRE_FALSE(divisible({1, 1, 1, 1, 10}));
    REQUIRE_FALSE(divisible({3, 5, 1}));
}


TEST_CASE("Test8") {
    REQUIRE(factorChain({1, 2, 4, 8, 16, 32}));
    REQUIRE(factorChain({1, 1, 1, 1, 1, 1}));
    REQUIRE(factorChain({10, 20, 40}));
    REQUIRE(factorChain({1, 1, 1, 1, 7, 49}));
    REQUIRE_FALSE(factorChain({2, 4, 6, 7, 12}));
    REQUIRE_FALSE(factorChain({10, 1}));
    REQUIRE_FALSE(factorChain({10, 20, 30, 40}));
}


TEST_CASE("Test9") {
    REQUIRE(concat({1, 3, 5}, {2, 6, 8}) == std::vector<int>({1, 3, 5, 2, 6, 8}));
    REQUIRE(concat({7, 8}, {10, 9, 1, 1, 2}) == std::vector<int>({7, 8, 10, 9, 1, 1, 2}));
    REQUIRE(concat({4, 5, 1}, {3, 3, 3, 3, 3}) == std::vector<int>({4, 5, 1, 3, 3, 3, 3, 3}));
}


TEST_CASE("Test10") {
    REQUIRE(isIdentical("kkkkk"));
    REQUIRE(isIdentical("ccc"));
    REQUIRE(isIdentical("bbbbbb"));
    REQUIRE_FALSE(isIdentical("ckkkk"));
    REQUIRE_FALSE(isIdentical("kkkkck"));
    REQUIRE_FALSE(isIdentical("aabc"));
    REQUIRE_FALSE(isIdentical("aabbbb"));
}


TEST_CASE("Test11") {
    REQUIRE(hammingDistance("abcde", "bcdef") == 5);
    REQUIRE(hammingDistance("abcde", "abcde") == 0);
    REQUIRE(hammingDistance("strong", "strung") == 1);
}


TEST_CASE("Test12") {
    REQUIRE(charCount('a', "edabit") == 1);
    REQUIRE(charCount('b', "big fat bubble") == 4);
    REQUIRE(charCount('f', "frank and his friends have offered five foxes for "
                           "sale") == 7);
    REQUIRE(charCount('c', "Chamber of secrets") == 1);
    REQUIRE(charCount('a', "Adam and Eve bit the apple and found a snake") == 6);
    REQUIRE(charCount('7', "10795426697") == 2);
    REQUIRE(charCount('s', "sssssssssssssssssssssssss") == 25);
    REQUIRE(charCount('x', "edabit") == 0);
}


TEST_CASE("Test13") {
    REQUIRE(mean(666) == 6);
    REQUIRE(mean(80) == 4);
    REQUIRE(mean(-13) == 2);
}


TEST_CASE("Test14") {
    REQUIRE(doubleLetters("loop"));
    REQUIRE(doubleLetters("meeting"));
    REQUIRE(doubleLetters("yummy"));
    REQUIRE(doubleLetters("moo"));
    REQUIRE(doubleLetters("toodles"));
    REQUIRE(doubleLetters("droop"));
    REQUIRE(doubleLetters("loot"));
    REQUIRE_FALSE(doubleLetters("munchkin"));
    REQUIRE_FALSE(doubleLetters("forestry"));
    REQUIRE_FALSE(doubleLetters("raindrops"));
    REQUIRE_FALSE(doubleLetters("gold"));
    REQUIRE_FALSE(doubleLetters("paradise"));
}


TEST_CASE("Test15") {
    REQUIRE(minimumRemovals({1, 2, 3, 4, 5}) == 1);
    REQUIRE(minimumRemovals({1, 2, 3, 4}) == 0);
    REQUIRE(minimumRemovals({5, 8, 8, 8}) == 1);
    REQUIRE(minimumRemovals({1, 8, 8, 8, 9, 9}) == 1);
    REQUIRE(minimumRemovals({2, 1, 8, 8, 8, 9, 9}) == 2);
    REQUIRE(minimumRemovals({8, 8, 9, 9}) == 0);
    REQUIRE(minimumRemovals({2, 1, 8, 8, 9, 9}) == 2);
    REQUIRE(minimumRemovals({9, 9, 8}) == 0);
    REQUIRE(minimumRemovals({7, 2}) == 1);
}


TEST_CASE("Test16") {
    REQUIRE(mauriceWins({3, 5, 10}, {4, 7, 11}));
    REQUIRE(mauriceWins({1, 8, 20}, {2, 9, 100}));
    REQUIRE(mauriceWins({2, 4, 10}, {3, 9, 11}));
    REQUIRE(mauriceWins({3, 8, 13}, {5, 11, 15}));
    REQUIRE_FALSE(mauriceWins({6, 8, 9}, {7, 12, 14}));
    REQUIRE_FALSE(mauriceWins({1, 2, 3}, {2, 3, 4}));
}


TEST_CASE("Test17") {
    REQUIRE(indexShuffle("abcdef") == "acebdf");
    REQUIRE(indexShuffle("abababab") == "aaaabbbb");
    REQUIRE(indexShuffle("it was a beautiful day") == "i a  euiu atwsabatfldy");
    REQUIRE(indexShuffle("maybe") == "myeab");
    REQUIRE(indexShuffle("holiday") == "hldyoia");
}


TEST_CASE("Test18") {
    REQUIRE(spelling("bee") == std::vector<std::string>({"b", "be", "bee"}));
    REQUIRE(spelling("cake") == std::vector<std::string>({"c", "ca", "cak", "cake"}));
    REQUIRE(spelling("happy") == std::vector<std::string>({"h", "ha", "hap", "happ", "happy"}));
    REQUIRE(spelling("eagerly") ==
            std::vector<std::string>({"e", "ea", "eag", "eage", "eager", "eagerl", "eagerly"}));
    REQUIRE(spelling("believe") ==
            std::vector<std::string>({"b", "be", "bel", "beli", "belie", "believ", "believe"}));
}


TEST_CASE("Test19") {
    REQUIRE(factorize(12) == std::vector<int>({1, 2, 3, 4, 6, 12}));
    REQUIRE(factorize(4) == std::vector<int>({1, 2, 4}));
    REQUIRE(factorize(17) == std::vector<int>({1, 17}));
    REQUIRE(factorize(24) == std::vector<int>({1, 2, 3, 4, 6, 8, 12, 24}));
    REQUIRE(factorize(1) == std::vector<int>({1}));
}


TEST_CASE("Test20") {
    REQUIRE(missingNum({1, 2, 3, 4, 6, 7, 8, 9, 10}) == 5);
    REQUIRE(missingNum({7, 2, 3, 6, 5, 9, 1, 4, 8}) == 10);
    REQUIRE(missingNum({7, 2, 3, 9, 4, 5, 6, 8, 10}) == 1);
    REQUIRE(missingNum({10, 5, 1, 2, 4, 6, 8, 3, 9}) == 7);
    REQUIRE(missingNum({1, 7, 2, 4, 8, 10, 5, 6, 9}) == 3);
}