#include "week02.hpp"
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <string>

using std::back_inserter;
// distance + 예외처리도 있으면 좋을 것 같다
auto findIndex(std::vector<std::string> const &src, std::string const &tgt) -> int
{
    // int result{};
    //  해당 iterator를 받아 - begin()으로 인덱스 확인
    // result = std::ranges::find(src, tgt) - src.begin();
    // return result;
    return std::distance(src.begin(), std::ranges::find(src, tgt));
}
// reduce 추천c++17 (accumulate는 c++98)
auto divisible(std::vector<int> const &src) -> bool
{
    // multiple 값과 plus 값을 계산 하여 나누어 지도록 계산
    auto product = std::reduce(src.begin(), src.end(), 1, std::multiplies<int>());
    auto sum = std::reduce(src.begin(), src.end(), 0, std::plus<int>());

    return product % sum == 0;
};
// vector bool은 사용하지 말아라, 왠만하면 선언을 자재하는 방향으로
auto factorChain(std::vector<int> const &src) -> bool
{
    // transform으로 앞뒤 index를 비교하며 나누어 떨어지는지 확인하고 all_of로 모두가 true 인지 확인
    std::vector<bool> boolr;
    boolr.reserve(src.size());
    bool result;
    // prev next 써봐라
    std::transform(src.begin(), src.end() - 1, src.begin() + 1, back_inserter(boolr),
                   [&](int a, int b) { return b % a == 0; });
    std::ranges::all_of(boolr, [&](auto &&s) { return result = s; });

    return result;
};

auto concat(std::vector<int> const &ls, std::vector<int> const &rs) -> std::vector<int>
{
    // ls를 먼저 옳기고 rs를 뒤에 이어붙혀준다
    std::vector<int> result;
    std::ranges::transform(ls, std::back_inserter(result), [](auto &&l) { return l; });
    std::ranges::transform(rs, std::back_inserter(result), [](auto &&r) { return r; });

    return result;
};

auto isIdentical(std::string const &src) -> bool
{
    // string을 확인하면서 같은 것만 있으면 true 아니면 false
    bool result{false};
    char firstchar = src[0];
    if (std::all_of(std::begin(src) + 1, std::end(src), [&](char ch) { return ch == firstchar; }))
    {
        return result = true;
    }
    return result;
};
// 왠만하면 transform과 reduce를 사용할 수 있다.
auto hammingDistance(std::string const &src0, std::string const &src1) -> int
{
    // string의 각 index의 char들이 다른 경우에 1씩 +한다.
    int result = std::inner_product(src0.begin(), src0.end(), src1.begin(), 0, std::plus<>(),
                                    [](char a, char b) { return a == b ? 0 : 1; });

    return result;
};
// TODO: 그냥 count를 사용 filter
auto charCount(char ch, std::string const &src) -> int
{
    // src에 ch가 몇개가 포함되어있는 지 확인하고 그 개수를 반환한다.
    auto result = std::ranges::count_if(src, [&](auto &&s) { return s == ch; });
    return result;
};
// transform reduce를 써보자
auto mean(int n) -> int
{
    // digit의 평균 값을 구라디 위해 절대값 처리하고 절대값 처리한 값을 단위별로 쪼개 서 더한 후 stirng으로 변환 후
    // 자리수를 캐스팅하여 나누어 계산했다.
    auto Sum = [](int num) {
        int sum = 0;
        while (num != 0)
        {
            sum += std::abs(num % 10);
            num /= 10;
        }
        return sum;
    };

    int absNum = std::abs(n);
    auto sumNum = Sum(absNum);
    auto count = static_cast<int>(std::to_string(absNum).size());
    return sumNum / count;
};
// equal_to사용해 봐라
auto doubleLetters(std::string const &src) -> bool
{
    // adjacent_find를 사용하여 처음 같은 값이 나오는 iter를 반환받고
    // 맞으면 위치 아니면 end() iter 반환 되기에 이를 이용해 true 값 반환한다.
    auto result{false};
    auto iter = std::ranges::adjacent_find(src, [](auto &&a, auto &&b) { return a == b; });
    if (iter != src.end())
        result = true;
    return result;
};

auto minimumRemovals(std::vector<int> const &src) -> int
{
    // acculate default인 plus를 이용하여 합이 짝수면 0반환, 그게 아니라면 앞 index부터  - 하며
    // 다시 짝수 일 때 까지다시 짝수 일 때 까지 minum removal 값을 ++시킨다
    int result{};
    auto sum = std::accumulate(src.begin(), src.end(), 0);
    if (sum % 2 == 0)
    {
        return result;
    }

    for (int s : src)
    {
        sum -= s;
        ++result;
        if (sum % 2 == 0)
        {
            return result;
        }
    }
};
// true false를 사용할 필요가 없다.
auto mauriceWins(std::vector<int> const &m, std::vector<int> const &s) -> bool
{
    // 초기자 리스트로 이기는 승리 패턴으로 초기화 후, 승리한 카운트가 2개 이상이면 승리한걸로 true값 반환
    auto round_results = {(m[0] > s[2]), (m[1] > s[0]), (m[2] > s[1])};
    int count_wins = std::count_if(round_results.begin(), round_results.end(), [](auto &&r) { return r; });

    return count_wins >= 2 ? true : false;
};
// partition_if?
auto indexShuffle(std::string const &src) -> std::string
{
    // 인덱스 % 2 == 0인 char를 우선 빈 string에 복사 후 인덱스 % 2 !=인 char를 이어서 복사 후 반환한다.
    std::string result{};
    int index{-1};
    std::copy_if(src.begin(), src.end(), std::back_inserter(result), [&](char c) {
        index++;
        return index % 2 == 0;
    });
    index = -1;
    std::copy_if(src.begin(), src.end(), std::back_inserter(result), [&](char c) {
        index++;
        return index % 2 != 0;
    });
    return result;
};
// 람다 안쪽에 선언하고 mutable을 사용해봐라
auto spelling(std::string const &src) -> std::vector<std::string>
{
    // 입력 된 string의 char를  빈 string에 추가하면 저장하고 그걸 반환한다.
    std::vector<std::string> result;
    std::string temp;
    std::transform(src.begin(), src.end(), std::back_inserter(result), [&](char c) {
        temp += c;
        return temp;
    });
    return result;
};

auto factorize(int n) -> std::vector<int>
{
    // 인수분해를 하기위해 1부터 n까지 값을 만들고, n과 나누어 떨어지는(인수)만 복사해 반환한다.
    std::vector<int> result;
    std::vector<int> numbers(n);
    std::iota(numbers.begin(), numbers.end(), 1);

    auto isFactor = [&](int i) { return n % i == 0; };

    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(result), isFactor);

    return result;
};

auto missingNum(std::vector<int> const &src) -> int
{
    // 10개의 수중에 빠진 수를 계산 하기 위해서 1부터 10까지 더한 55에서 - src의 합을 빼준다.
    auto nums{55};
    auto sums = std::accumulate(src.begin(), src.end(), 0);

    return nums - sums;
};