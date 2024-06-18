
#include <algorithm>
#include <vector>
#include <string>
auto correctStream(std::vector<std::string> const& src,
                   std::vector<std::string> const& tgt) -> std::vector<int>;
auto negate(std::vector<int> const& src) -> std::vector<int>;
auto existsHigher(std::vector<int> const& src, int n) -> bool;
auto addEnding(std::vector<std::string> const& src,
               std::string const&              sfx) -> std::vector<std::string>;
auto differenceMaxMin(std::vector<int> const& src) -> int;