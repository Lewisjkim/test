#include "week02.hpp"
#include <__algorithm/ranges_any_of.h>
#include <algorithm>

auto findIndex(std::vector<std::string> const& src, std::string const& tgt) -> int {
    int result{};
    result = std::ranges::find(src,tgt) - src.begin();

    return result;
};
auto divisible(std::vector<int> const& src) -> bool { 
    auto result{false};
    // //  7. Product Divisible By Sum?
    // //  Write a function that, given a vector of integers, returns true if the
    // // product of the vector is divisible by the sum of that same vector.
    return true; 
    };
auto factorChain(std::vector<int> const& src) -> bool { return true; };
auto concat(std::vector<int> const& ls, std::vector<int> const& rs) -> std::vector<int> {
    std::vector<int>a{1};
    return a;
};
auto isIdentical(std::string const& src) -> bool { return true; };
auto hammingDistance(std::string const& src0, std::string const& src1) -> int { return 1; };
auto charCount(char ch, std::string const& src) -> int { return 1; };
auto mean(int n) -> int { return 1; };
auto doubleLetters(std::string const& src) -> bool { return 1; };
auto minimumRemovals(std::vector<int> const& src) -> int { return 1; };
auto mauriceWins(std::vector<int> const& m, std::vector<int> const& s) -> bool { return 1; };
auto indexShuffle(std::string const& src) -> std::string { return "true"; };
auto spelling(std::string const& src) -> std::vector<std::string> {
    std::vector<std::string> a{"hi"};
    return a;
};
auto factorize(int n) -> std::vector<int> {
    std::vector<int> a{1};
    return a;
};
auto missingNum(std::vector<int> const& src) -> int { return 1; };