#include "week03.hpp"
#include <algorithm>
#include <cctype>
#include <iterator>
#include <regex>
#include <sstream>

#include <unordered_set>
// 21
auto Week3::identicalFilter(std::vector<std::string> const &arr) -> std::vector<std::string>
{
    // vector<string> 중 반복되는 string만 or 사이즈 1인 vector<string>타입으로 반환해라 - remove sort 사용
    std::vector<std::string> result;

    std::copy_if(arr.begin(), arr.end(), std::back_inserter(result), [](auto &&s) {
        std::unordered_set<char> uset(s.begin(), s.end());
        return uset.size() == 1;
    });

    return result;
}
// 22
auto Week3::shiftL(std::vector<int> const &arr, int num) -> std::vector<int>
{
    // left shift function which shifts amount as num -> using std::rotate
    std::vector<int> result = arr;
    std::rotate(result.begin(), result.begin() + num % arr.size(), result.end());
    return result;
}

auto Week3::shiftR(std::vector<int> const &arr, int num) -> std::vector<int>
{
    std::vector<int> result = arr; // = arr;
    std::rotate(result.begin(), result.end() - num % arr.size(), result.end());
    return result;
}
// 23
auto Week3::setFrom(std::vector<int> const &arr) -> std::vector<int>
{
    std::vector<int> result = arr;
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
};
// 24
auto Week3::firstAndLast(std::string const &s) -> std::vector<std::string>
{
    std::string src = s;
    std::vector<std::string> result;
    std::sort(src.begin(), src.end());
    result.push_back(src);
    std::sort(src.begin(), src.end(), std::greater<>());
    result.push_back(src);
    return result;
};
// 25
auto Week3::convertCartesian(std::vector<int> const &x, std::vector<int> const &y) -> std::vector<std::vector<int>>
{
    std::vector<std::vector<int>> result;
    result.reserve(x.size());
    std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(result),
                   [](int a, int b) { return std::vector<int>{a, b}; });

    return result;
}
// 26
auto Week3::sortByLength(std::vector<std::string> const &arr) -> std::vector<std::string>
{
    std::vector<std::string> result{arr};
    std::sort(result.begin(), result.end(), [](std::string a, std::string b) { return a.size() < b.size(); });
    return result;
}
// 27
auto Week3::countAdverbs(std::string const &s) -> int
{
    std::istringstream iss(s); // Create a string stream from the input sentence
    std::string word;
    int count = 0;

    // Read each word from the string stream
    while (iss >> word)
    {
        // Remove trailing period if present
        if (!word.empty() && word.back() == '.' || !word.empty() && word.back() == ',')
        {
            word.pop_back();
        }

        // Check if the word ends with "ly"
        if (word.length() >= 2 && word.substr(word.length() - 2) == "ly")
        {
            count++;
        }
    }

    return count;
}
// 28
auto Week3::societyName(std::vector<std::string> const &friends) -> std::string
{
    // 각 string의 1st index를 받은 후 sort
    std::string result;
    for (auto &f : friends)
    {
        result += f[0];
    }
    std::sort(result.begin(), result.end());
    return result;
}
// 29
auto Week3::isPalindrome(std::string const &str) -> bool
{
    bool result{false};
    std::string filterstr;
    std::transform(str.begin(), str.end(), std::back_inserter(filterstr), [](char a) { return std::tolower(a); });
    filterstr.erase(std::remove_if(filterstr.begin(), filterstr.end(),
                                   [](char c) { return !std::isalnum(static_cast<unsigned char>(c)); }),
                    filterstr.end());

    return std::equal(filterstr.begin(), filterstr.begin() + filterstr.size() / 2, filterstr.rbegin());
}
// 30
auto Week3::countUnique(std::string const &str1, std::string const &str2) -> int
{
    // wrong
    std::unordered_set<char> uniqueChars;

    // Insert characters from str1 into the set
    for (char c : str1)
    {
        uniqueChars.insert(c);
    }

    // Insert characters from str2 into the set
    for (char c : str2)
    {
        uniqueChars.insert(c);
    }

    // Return the size of the set, which represents the number of unique characters
    return static_cast<int>(uniqueChars.size());
}

// 31
auto Week3::isValidPhoneNumber(std::string const &str) -> bool
{
    std::string expectedFormat = "(###) ###-####";

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (expectedFormat[i] == '#')
        {
            if (!std::isdigit(str[i]))
            {
                return false;
            }
        }
        else
        {
            if (str[i] != expectedFormat[i])
            {
                return false;
            }
        }
    }

    return true;
}
// 32
auto Week3::tree(int h) -> std::vector<std::string>
{
    std::vector<std::string> result;

    for (int i = 1; i <= h; ++i)
    {
        int spaces = h - i;
        int hashes = 2 * i - 1;

        // Construct line: spaces + hashes + spaces
        std::string line(spaces + hashes + spaces, ' ');                       // Create a line of appropriate size
        std::fill(line.begin() + spaces, line.begin() + spaces + hashes, '#'); // Fill hashes in the middle
        result.push_back(line);
    }

    return result;
}
// 33
auto Week3::accum(std::string const &s) -> std::string
{
    std::string result;

    for (int i = 0; i < s.size(); ++i)
    {
        if (i > 0)
        {
            result += '-';
        }

        result += std::toupper(s[i]); // Capitalize current character

        for (int j = 0; j < i; ++j)
        {
            result += std::tolower(s[i]); // Append lowercase characters based on index
        }
    }

    return result;
}
// 34
auto Week3::unique(std::vector<double> const &arr) -> double
{
    std::unordered_map<double, int> countMap;

    // Count occurrences of each number
    for (double num : arr)
    {
        countMap[num]++;
    }

    // Find the number with count 1 (unique number)
    for (auto const &pair : countMap)
    {
        if (pair.second == 1)
        {
            return pair.first;
        }
    }

    // If no unique number found, return a default value (or handle error as needed)
    return std::numeric_limits<double>::quiet_NaN();
}
// 35
auto Week3::isAnagram(std::string const &s1, std::string const &s2) -> bool
{
    std::string lower_s1 = s1;
    std::string lower_s2 = s2;

    std::transform(lower_s1.begin(), lower_s1.end(), lower_s1.begin(), [](unsigned char c) { return std::tolower(c); });

    std::transform(lower_s2.begin(), lower_s2.end(), lower_s2.begin(), [](unsigned char c) { return std::tolower(c); });

    // Sort both strings
    std::sort(lower_s1.begin(), lower_s1.end());
    std::sort(lower_s2.begin(), lower_s2.end());

    // Compare sorted strings
    return lower_s1 == lower_s2;
}