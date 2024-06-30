#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../week03.hpp"
#include <doctest/doctest.h>
TEST_CASE("Test21")
{
    REQUIRE_EQ(Week3::identicalFilter({"aaaaaa", "bc", "d", "eeee", "xyz"}),
               std::vector<std::string>({"aaaaaa", "d", "eeee"}));
    REQUIRE_EQ(Week3::identicalFilter({"88", "999", "22", "545", "133"}),
               std::vector<std::string>({"88", "999", "22"}));
    REQUIRE_EQ(Week3::identicalFilter({"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}), std::vector<std::string>({}));
    REQUIRE_EQ(Week3::identicalFilter({"1", "2", "3"}), std::vector<std::string>({"1", "2", "3"}));
}

TEST_CASE("Test22")
{
    REQUIRE_EQ(Week3::shiftL({1, 2, 3, 4}, 1), std::vector<int>({2, 3, 4, 1}));
    REQUIRE_EQ(Week3::shiftL({1, 2, 3, 4, 5}, 3), std::vector<int>({4, 5, 1, 2, 3}));
    REQUIRE_EQ(Week3::shiftL({1, 2, 3, 4, 5}, 5), std::vector<int>({1, 2, 3, 4, 5}));
    REQUIRE_EQ(Week3::shiftL({1, 2, 3, 4, 5}, 6), std::vector<int>({2, 3, 4, 5, 1}));
    REQUIRE_EQ(Week3::shiftL({1, 2, 3, 4, 5}, 1), std::vector<int>({2, 3, 4, 5, 1}));
    REQUIRE_EQ(Week3::shiftL({1, 2, 3, 4, 5}, 4), std::vector<int>({5, 1, 2, 3, 4}));

    REQUIRE_EQ(Week3::shiftR({1, 2, 3, 4, 5}, 1), std::vector<int>({5, 1, 2, 3, 4}));
    REQUIRE_EQ(Week3::shiftR({1, 2, 3, 4, 5}, 3), std::vector<int>({3, 4, 5, 1, 2}));
    REQUIRE_EQ(Week3::shiftR({1, 2, 3, 4, 5}, 0), std::vector<int>({1, 2, 3, 4, 5}));
    REQUIRE_EQ(Week3::shiftR({1, 2, 3, 4, 5}, 15), std::vector<int>({1, 2, 3, 4, 5}));
    REQUIRE_EQ(Week3::shiftR({1, 2, 3, 4}, 1), std::vector<int>({4, 1, 2, 3}));
}

TEST_CASE("Test23")
{
    REQUIRE_EQ(Week3::setFrom({1, 3, 3, 5, 5}), std::vector<int>({1, 3, 5}));
    REQUIRE_EQ(Week3::setFrom({4, 4, 4, 4, 4}), std::vector<int>({4}));
    REQUIRE_EQ(Week3::setFrom({5, 7, 8, 9, 10, 15}), std::vector<int>({5, 7, 8, 9, 10, 15}));
    REQUIRE_EQ(Week3::setFrom({5, 9, 9}), std::vector<int>({5, 9}));
    REQUIRE_EQ(Week3::setFrom({1, 2, 3, 4, 5, 5, 6}), std::vector<int>({1, 2, 3, 4, 5, 6}));
    REQUIRE_EQ(Week3::setFrom({1, 1, 2, 2, 2}), std::vector<int>({1, 2}));
}
TEST_CASE("Test24")
{
    REQUIRE_EQ(Week3::firstAndLast("marmite"), std::vector<std::string>({"aeimmrt", "trmmiea"}));
    REQUIRE_EQ(Week3::firstAndLast("bench"), std::vector<std::string>({"bcehn", "nhecb"}));
    REQUIRE_EQ(Week3::firstAndLast("scoop"), std::vector<std::string>({"coops", "spooc"}));
    REQUIRE_EQ(Week3::firstAndLast("fanatic"), std::vector<std::string>({"aacfint", "tnifcaa"}));
}
TEST_CASE("Test25")
{
    REQUIRE_EQ(Week3::convertCartesian({1, 1}, {1, 1}), std::vector<std::vector<int>>({{1, 1}, {1, 1}}));
    REQUIRE_EQ(Week3::convertCartesian({9, 8, 3}, {1, 1, 1}), std::vector<std::vector<int>>({{9, 1}, {8, 1}, {3, 1}}));
    REQUIRE_EQ(Week3::convertCartesian({2, 5, 1}, {7, 8, 9}), std::vector<std::vector<int>>({{2, 7}, {5, 8}, {1, 9}}));
    REQUIRE_EQ(Week3::convertCartesian({3, 2, 2}, {6, 1, 7}), std::vector<std::vector<int>>({{3, 6}, {2, 1}, {2, 7}}));
    REQUIRE_EQ(Week3::convertCartesian({3, 2, 2, 0}, {6, 1, 7, 1}),
               std::vector<std::vector<int>>({{3, 6}, {2, 1}, {2, 7}, {0, 1}}));
}
TEST_CASE("Test26")
{
    REQUIRE_EQ(Week3::sortByLength({"a", "ccc", "dddd", "bb"}), std::vector<std::string>({"a", "bb", "ccc", "dddd"}));
    REQUIRE_EQ(Week3::sortByLength({"apple", "pie", "shortcake"}),
               std::vector<std::string>({"pie", "apple", "shortcake"}));
    REQUIRE_EQ(Week3::sortByLength({"may", "april", "september", "august"}),
               std::vector<std::string>({"may", "april", "august", "september"}));
    REQUIRE_EQ(Week3::sortByLength({"maybe"}), std::vector<std::string>({"maybe"}));
    REQUIRE_EQ(Week3::sortByLength({}), std::vector<std::string>({}));
}
TEST_CASE("Test27")
{
    SUBCASE("Basic")
    {
        REQUIRE_EQ(Week3::countAdverbs("She ran hurriedly towards the stadium."), 1);
        REQUIRE_EQ(Week3::countAdverbs("She ate the lasagna heartily and noisily."), 2);
        REQUIRE_EQ(Week3::countAdverbs("He hates potatoes."), 0);
        REQUIRE_EQ(Week3::countAdverbs("He was happily, crazily, foolishly over the "
                                       "moon."),
                   3);
        REQUIRE_EQ(Week3::countAdverbs("She writes poetry beautifully."), 1);
        REQUIRE_EQ(Week3::countAdverbs("There are many fat geese in the park."), 0);
        REQUIRE_EQ(Week3::countAdverbs("The horse acted aggressively and stubbornly."), 2);
    }

    SUBCASE("Only count ly as word endings")
    {
        REQUIRE_EQ(Week3::countAdverbs("She forgot where to buy the lysol."), 0);
        REQUIRE_EQ(Week3::countAdverbs("Ilya ran to the store."), 0);
    }
}
TEST_CASE("Test28")
{
    REQUIRE_EQ(Week3::societyName({"Adam", "Sarah", "Malcolm"}), "AMS");
    REQUIRE_EQ(Week3::societyName({"Phoebe", "Chandler", "Ross", "Rachel", "Monica", "Joey"}), "CJMPRR");
    REQUIRE_EQ(Week3::societyName({"Harry", "Newt", "Luna", "Cho"}), "CHLN");
    REQUIRE_EQ(Week3::societyName({"Sherlock", "Irene", "John"}), "IJS");
    REQUIRE_EQ(Week3::societyName({"Sheldon", "Amy", "Penny", "Howard", "Raj"}), "AHPRS");
}
TEST_CASE("Test29")
{
    REQUIRE_EQ(Week3::isPalindrome("A man, a plan, a cat, a ham, a yak, a yam, a hat, "
                                   "a canal-Panama!"),
               true);
    REQUIRE_EQ(Week3::isPalindrome("Neuquen"), true);
    REQUIRE_EQ(Week3::isPalindrome("Not a palindrome"), false);
}
TEST_CASE("Test30")
{
    REQUIRE_EQ(Week3::countUnique("apple", "play"), 5);
    REQUIRE_EQ(Week3::countUnique("sore", "zebra"), 7);
    REQUIRE_EQ(Week3::countUnique("pip", "geeks"), 6);
    REQUIRE_EQ(Week3::countUnique("a", "soup"), 5);
    REQUIRE_EQ(Week3::countUnique("maniac", "maniac"), 5);
}
TEST_CASE("Test31")
{
    REQUIRE(Week3::isValidPhoneNumber("(123) 456-7890"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(1111)555 2345"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(098) 123 4567"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(123)456-7890"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("abc(123)456-7890"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(123)456-7890abc"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("abc(123)456-7890abc"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("abc(123) 456-7890"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(123) 456-7890abc"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("abc(123) 456-7890abc"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(123)-456-7890"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("(123)_456-7890"));
    REQUIRE_FALSE(Week3::isValidPhoneNumber("-123) 456-7890"));
    REQUIRE(Week3::isValidPhoneNumber("(519) 505-6498"));
}
TEST_CASE("Test32")
{
    REQUIRE_EQ(Week3::tree(1), std::vector<std::string>({"#"}));
    REQUIRE_EQ(Week3::tree(2), std::vector<std::string>({" # ", "###"}));
    REQUIRE_EQ(Week3::tree(5),
               std::vector<std::string>({"    #    ", "   ###   ", "  #####  ", " ####### ", "#########"}));
    REQUIRE_EQ(Week3::tree(0), std::vector<std::string>({}));
}
TEST_CASE("Test33")
{
    REQUIRE_EQ(Week3::accum("abcd"), "A-Bb-Ccc-Dddd");
    REQUIRE_EQ(Week3::accum("RqaEzty"), "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
    REQUIRE_EQ(Week3::accum("cwAt"), "C-Ww-Aaa-Tttt");
    REQUIRE_EQ(Week3::accum("VgyCdnQa"), "V-Gg-Yyy-Cccc-Ddddd-Nnnnnn-Qqqqqqq-Aaaaaaaa");
    REQUIRE_EQ(Week3::accum("nRBSdNOsMl"), "N-Rr-Bbb-Ssss-Ddddd-Nnnnnn-Ooooooo-Ssssssss-"
                                           "Mmmmmmmmm-Llllllllll");
    REQUIRE_EQ(Week3::accum("nuE"), "N-Uu-Eee");
    REQUIRE_EQ(Week3::accum("RlDrhZuQaqsoHEfziByObtMxkFCJVe"),
               "R-Ll-Ddd-Rrrr-Hhhhh-Zzzzzz-Uuuuuuu-Qqqqqqqq-Aaaaaaaaa-"
               "Qqqqqqqqqq-"
               "Sssssssssss-Oooooooooooo-Hhhhhhhhhhhhh-Eeeeeeeeeeeeee-"
               "Fffffffffffffff-Zzzzzzzzzzzzzzzz-Iiiiiiiiiiiiiiiii-"
               "Bbbbbbbbbbbbbbbbbb-Yyyyyyyyyyyyyyyyyyy-Oooooooooooooooooooo-"
               "Bbbbbbbbbbbbbbbbbbbbb-Tttttttttttttttttttttt-"
               "Mmmmmmmmmmmmmmmmmmmmmmm-Xxxxxxxxxxxxxxxxxxxxxxxx-"
               "Kkkkkkkkkkkkkkkkkkkkkkkkk-Ffffffffffffffffffffffffff-"
               "Ccccccccccccccccccccccccccc-Jjjjjjjjjjjjjjjjjjjjjjjjjjjj-"
               "Vvvvvvvvvvvvvvvvvvvvvvvvvvvvv-Eeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
    REQUIRE_EQ(Week3::accum("EXpzPFx"), "E-Xx-Ppp-Zzzz-Ppppp-Ffffff-Xxxxxxx");
    REQUIRE_EQ(Week3::accum("NU"), "N-Uu");
    REQUIRE_EQ(Week3::accum("g"), "G");
}
TEST_CASE("Test34")
{
    REQUIRE_EQ(Week3::unique({3, 3, 3, 7, 3, 3}), 7);
    REQUIRE_EQ(Week3::unique({0, 0, 0.77, 0, 0}), 0.77);
    REQUIRE_EQ(Week3::unique({0, 1, 1, 1, 1, 1, 1, 1}), 0);
    REQUIRE_EQ(Week3::unique({-4, -4, -4, 4}), 4);
    REQUIRE_EQ(Week3::unique({8, 8, 8, 8, 8, 8, 8, 0.5}), 0.5);
    REQUIRE_EQ(Week3::unique({2, 1, 2, 2, 2, 2, 2, 2}), 1);
}
TEST_CASE("Test35")
{
    REQUIRE_EQ(Week3::isAnagram("cristian", "Cristina"), true);
    REQUIRE_EQ(Week3::isAnagram("Dave Barry", "Ray Adverb"), true);
    REQUIRE_EQ(Week3::isAnagram("Nope", "Note"), false);
    REQUIRE_EQ(Week3::isAnagram("Apple", "Appeal"), false);
}