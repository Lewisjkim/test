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
    // using std::rotate함수를 사용해서 왼쪽으로 shift하였다
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
    // std::unique와 erase를 같이 사용해서 한개 이상인 단어들을 제거함.
    std::vector<int> result = arr;
    result.erase(std::unique(result.begin(), result.end()), result.end());
    return result;
};
// 24
auto Week3::firstAndLast(std::string const &s) -> std::vector<std::string>
{
    // std::sort를 사용하여 오름차순 내림차순 값을 전달함.
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
    // x,y 벡터 동일 index 항목을 한쌍으로 묶었다.
    std::vector<std::vector<int>> result;
    result.reserve(x.size());
    std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(result),
                   [](int a, int b) { return std::vector<int>{a, b}; });

    return result;
}
// 26
auto Week3::sortByLength(std::vector<std::string> const &arr) -> std::vector<std::string>
{
    // 입력 받은 string vector의 앞뒤 string 사이즈를 비교하여 작은 사이즈의 string을 앞으로 오게 분류함.
    std::vector<std::string> result{arr};
    std::sort(result.begin(), result.end(), [](std::string a, std::string b) { return a.size() < b.size(); });
    return result;
}
// 27
auto Week3::countAdverbs(std::string const &s) -> int
{
    // istringstream을 통해 문자열을 넣고
    std::istringstream iss(s);
    std::string word;
    int count{};

    // 스트링 스트림에 있는 단어를 읽어간다.
    while (iss >> word)
    {
        // 단어 뒤에 문자가 있거나 "." 또는","가 있으면 해당 단어를 제거.
        if (!word.empty() && word.back() == '.' || !word.empty() && word.back() == ',')
        {
            word.pop_back();
        }

        // 단어 길이가 2 이상이고 단어의 길이에서 -2개를 뺸 string이 ly일 경우 count++
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
    // 거꾸로 해도 같은지 확인 하기 위해
    std::string filterstr;

    // 우선 소문자로 만들고 filterstr에 넣는다. 그리고 isalnum과 remove_if를 이용해 숫자나알파벳이 아니면 (true)뒤로
    // 보내고 erase를 통해서 지워질 부분을 지운다.
    std::transform(str.begin(), str.end(), std::back_inserter(filterstr), [](char a) { return std::tolower(a); });
    filterstr.erase(std::remove_if(filterstr.begin(), filterstr.end(), [](char c) { return !std::isalnum(c); }),
                    filterstr.end());
    // 반절에서 앞뒤가 같은지 비교하여 같으면 true반환.
    return std::equal(filterstr.begin(), filterstr.begin() + filterstr.size() / 2, filterstr.rbegin());
}
// 30
auto Week3::countUnique(std::string const &str1, std::string const &str2) -> int
{
    // set을 이용해서 우선 str1을 넣어주고 str2를 넣어준다. unordered_set의 특성으로 분류된 값들의 사이즈를 int로
    // 캐스팅해서 반환한다.
    std::unordered_set<char> uniqueChars;

    for (auto &c : str1)
    {
        uniqueChars.insert(c);
    }

    for (auto &c : str2)
    {
        uniqueChars.insert(c);
    }

    return static_cast<int>(uniqueChars.size());
}

// 31
auto Week3::isValidPhoneNumber(std::string const &str) -> bool
{
    // 양식을 만들고 양식 index가 #일때 숫자가 아니거나 양식과 형태가 나르면 false반환
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
    //
    std::vector<std::string> result;

    for (int i = 1; i <= h; ++i)
    {
        int spaces = h - i;
        int hashes = 2 * i - 1;

        std::string line(spaces + hashes + spaces, ' '); // 사이즈 만큼의 빈공간
        std::fill(line.begin() + spaces, line.begin() + spaces + hashes,
                  '#'); // space 다음부터 hash 끝 위치까지 #으로 채운다
        result.push_back(line);
    }

    return result;
}
// 33
auto Week3::accum(std::string const &s) -> std::string
{
    // 첫번째 인덱스만 대문자로 만들고 나머지는 소문자로 만들었다. 인덱스가 1부터 -추가했다.
    std::string result;

    for (int i = 0; i < s.size(); ++i)
    {
        if (i > 0)
        {
            result += '-';
        }

        result += std::toupper(s[i]);

        for (int j = 0; j < i; ++j)
        {
            result += std::tolower(s[i]);
        }
    }

    return result;
}
// 34
auto Week3::unique(std::vector<double> const &arr) -> double
{
    // vector를 정렬한 후, 혼자 있는 값이면 해당 값을 반환
    std::vector<double> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    for (size_t i = 0; i < sortedArr.size(); ++i)
    {
        if ((i == 0 || sortedArr[i] != sortedArr[i - 1]) && (sortedArr[i] != sortedArr[i + 1]))
        {
            return sortedArr[i];
        }
    }
}
// 35
auto Week3::isAnagram(std::string const &s1, std::string const &s2) -> bool
{
    // 철자 바꾸기는 곧 같은 char들이 같은 개수만큼 사용 되었다는 것으로 소문자로 만들어 분류후
    std::string case1 = s1;
    std::string case2 = s2;

    std::transform(case1.begin(), case1.end(), case1.begin(), [](char c) { return std::tolower(c); });
    std::transform(case2.begin(), case2.end(), case2.begin(), [](char c) { return std::tolower(c); });

    std::sort(case1.begin(), case1.end());
    std::sort(case2.begin(), case2.end());

    return case1 == case2;
}