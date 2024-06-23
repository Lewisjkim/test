#include "week02.hpp"
#include <__algorithm/ranges_adjacent_find.h>
#include <__algorithm/ranges_all_of.h>
#include <__algorithm/ranges_any_of.h>
#include <__algorithm/ranges_copy_if.h>
#include <__algorithm/ranges_count_if.h>
#include <__algorithm/ranges_find_if.h>
#include <__algorithm/ranges_mismatch.h>
#include <__algorithm/ranges_transform.h>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <string>

auto findIndex(std::vector<std::string> const& src, std::string const& tgt) -> int {
    int result{};
    result = std::ranges::find(src,tgt) - src.begin();

    return result;
};

auto divisible(std::vector<int> const& src) -> bool { 
    auto product = std::accumulate(src.begin(), src.end(),1,std::multiplies<int>());
    auto sum = std::accumulate(src.begin(),src.end(),0);

    return product % sum == 0 ? true : false; 
};
    
auto factorChain(std::vector<int> const& src) -> bool { 
    std::vector<bool>boolr;
    boolr.reserve(src.size());
    bool result;

    std::transform(src.begin(),src.end()-1, src.begin()+1, 
    std::back_inserter(boolr),[&](int a, int b){ return b % a == 0; });

    std::ranges::all_of(boolr,[&](auto&& s){return result = s; });
    return result;
};

auto concat(std::vector<int> const& ls, std::vector<int> const& rs) -> std::vector<int> {
    std::vector<int>result;
    std::ranges::transform(ls,std::back_inserter(result), [](auto&& l){return l;});
    std::ranges::transform(rs,std::back_inserter(result), [](auto&& r){return r;});

    return result;
};

auto isIdentical(std::string const& src) -> bool { 
    // //  10. Check if a String Contains only Identical Characters
    // //  Write a function that returns true if all characters in a string are
    // // identical and false otherwise.    
    bool result{false};
    char firstchar = src[0];
    if(std::all_of(std::begin(src)+1,std::end(src),[&](char ch){return ch == firstchar;}))
    {
        return result = true;
    }
    return result; 
};

auto hammingDistance(std::string const& src0, std::string const& src1) -> int { 
    int result = std::inner_product(src0.begin(), src0.end(), 
    src1.begin(), 0, std::plus<>(), [](char a, char b) {
    return a == b ? 0 : 1; });

    return result; 
};

auto charCount(char ch, std::string const& src) -> int { 
    // //  12. Count Instances of a Characters in a String
    // //  Create a function that takes two strings as arguments and returns the
    // // number of times the first string is found in the second string.
    // //  Your output must be case-sensitive (see assertion #4).
    auto result = std::ranges::count_if(src,[&](auto&& s){return s == ch;});
    return  result;
};

auto mean(int n) -> int { 
    // //  13. Mean of All Digits
    // //  Create a function that returns the mean of all digits.
    // //  The mean will always be a integer.
    auto Sum = [](int num) {int sum = 0;
    while (num != 0) {
        sum += std::abs(num % 10); // Add the last digit to sum
        num /= 10;       // Remove the last digit
    }
    return sum;};

    int absNum = std::abs(n);
    auto sumNum = Sum(absNum);
    auto count = static_cast<int>(std::to_string(absNum).size());
    return sumNum / count; 
};

auto doubleLetters(std::string const& src) -> bool {
    // //  14. Double Letters
    // //  Create a function that takes a word and returns true if the word has
    // // two consecutive identical letters.
    //맞으면 위치 아니면 end() iter 반환
    auto result{false};
    auto iter = std::ranges::adjacent_find(src,[](auto&& a, auto&& b){return a == b;});
    if(iter != src.end()) result = true;
    return result;
};

auto minimumRemovals(std::vector<int> const& src) -> int { 
    // //  15. Minimum Removals to Make Sum Even
    // //  Create a function that returns the minimum number of removals to make
    // // the sum of all elements in a vector even.
    // //  If the sum is already even, return 0 (see assertion #2, #6 and #8).return 1; }
    int result{};
    auto sum = std::accumulate(src.begin(),src.end(),0);
    if(sum % 2 == 0)
    {
        return result;
    }

    // Find and remove elements until sum becomes even
    for (int s : src) {
        sum -= s;
        ++result;
        if (sum % 2 == 0) {
            return result;
        }
    }
};

auto mauriceWins(std::vector<int> const& m, std::vector<int> const& s) -> bool { 
    auto round_results = {
        (m[0] > s[2]), // Maurice's slowest vs Steve's fastest
        (m[1] > s[0]), // Maurice's middle vs Steve's slowest
        (m[2] > s[1])  // Maurice's fastest vs Steve's middle
    };
    int count_wins = std::count_if(round_results.begin(),round_results.end(), [](auto&& r){return r;});

    return count_wins >= 2 ? true : false;
};

auto indexShuffle(std::string const& src) -> std::string { 
    // //  17. Index Shuffle
    // //  Create a function that takes all even-indexed characters and odd-indexed
    // // characters from a string and concatenates them together.
    //return evenindex value + oddindex value
    //std::string temp{src};
    std::string result{};
    int index{-1};
    std::copy_if(src.begin(),src.end(),std::back_inserter(result),[&](char c)
    {index++;return index % 2 == 0;});
    index = -1;
    std::copy_if(src.begin(),src.end(),std::back_inserter(result),[&](char c)
    {index++;return index % 2 != 0;});
    return result;
};

auto spelling(std::string const& src) -> std::vector<std::string> {
// //  18. Spelling it Out
// //  Create a function which takes in a word and spells it out,
// // by consecutively adding letters until the full word is completed.
    std::vector<std::string> result;
    std::string temp;
    std::transform(src.begin(), src.end(), std::back_inserter(result),
                   [&](char c) {
                       temp += c;
                       return temp;
                   });
    return result;
};

auto factorize(int n) -> std::vector<int> {
// //  19. Factorize a Number
// //  Create a function that takes a number as its argument and returns a
// // vector of all its factors.
// //  The input integer will be positive.
// //  A factor is a number that evenly divides into another number without
// //  leaving a remainder.
std::vector<int> result;
std::vector<int> numbers(n);
    std::iota(numbers.begin(), numbers.end(), 1);
    
    // Lambda function to check if a number is a factor of 'num'
    auto isFactor = [&](int i) {
        return n % i == 0;
    };
    
    // Copy factors into 'factors' vector using std::copy_if
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(result), isFactor);
    
    return result;
};

auto missingNum(std::vector<int> const& src) -> int { 
// //  20. Find the Missing Number
// //  Create a function that takes a vector of integers between 1 and 10
// // (excluding one number) and returns the missing number.
// //  The vector of numbers will be unsorted (not in order).
// //  Only one number will be missing.
auto nums{55};
auto sums = std::accumulate(src.begin(),src.end(),0);

return nums - sums; 
};