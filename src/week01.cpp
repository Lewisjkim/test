#include "week01.hpp"
#include <__algorithm/ranges_minmax.h>
#include <algorithm>
#include <iterator>

auto correctStream(std::vector<std::string> const& src,
                   std::vector<std::string> const& tgt) -> std::vector<int> {
    std::vector<int> result;
    result.reserve(src.size());
    std::ranges::transform(src,tgt, std::back_inserter(result), [](auto&& s, auto&& t){return s == t ? 1 : -1;});

    return result;
}

auto negate(std::vector<int> const& src) -> std::vector<int> {
    std::vector<int> result;
    result.reserve(src.size());
    std::ranges::transform(src, std::back_inserter(result), std::negate<int>());

    return result;
}

auto existsHigher(std::vector<int> const& src, int n) -> bool {
    bool result{false};
    std::ranges::find_if(src,[&](auto&& s){return result = s > n ? true : false;});
   
    return result;
}

auto addEnding(std::vector<std::string> const& src,
               std::string const& sfx) -> std::vector<std::string> {
    std::vector<std::string> result;
    result.reserve(src.size());
    std::ranges::transform(src, std::back_inserter(result), [&](auto&& s){return s + sfx;});
   
    return result;
}

auto differenceMaxMin(std::vector<int> const& src) -> int {
    auto minmax = std::ranges::minmax(src);
    auto result = minmax.max - minmax.min;
   
    return result;
}