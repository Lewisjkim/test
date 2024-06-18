#include "week01.hpp"

// 우리코드

//  1. Typing Game
//  Create a function that takes in two arrays: the array of user-typed words,
// and the array of correctly-typed words and outputs an array containing 1s
// (correctly-typed words) and -1s (incorrectly-typed words).
auto correctStream(std::vector<std::string> const& src,
                   std::vector<std::string> const& tgt) -> std::vector<int> {
    std::vector<int> result(src.size(), 0);
    for(size_t i = 0; i < src.size(); i++) {
        if(src[i].compare(tgt[i]) == 0) {
            result[i] = 1;
        } else {
            result[i] = -1;
        }
    }
    return result;
}

// //  2. Negate the List
// //  Given a vector of integers, negate all the elements in the vector.
// //  If the vector is empty, return an empty vector.
auto negate(std::vector<int> const& src) -> std::vector<int> {
    std::vector<int> result(src.size(), 0);
    if(0 == src.size())
        return result;

    for(size_t i = 0; i < src.size(); i++) {
        result[i] = src[i] * -1;
    }
    return result;
}

// //  3. Exists a Number Higher?
// //  Write a function that, given a vector of integers, returns true if
// // there exists at least one number that is larger than or equal to n.
// //  Return false for an empty array.
auto existsHigher(std::vector<int> const& src, int n) -> bool {
    bool result{false};
    if(src.size() == 0) {
        return result;
    }

    for(const auto& s : src) {
        if(s > n) {
            result = true;
            return result;
        }
    }
    return result;
}

// //  4. Word Endings
// //  Create a function that adds a string ending to each member in
// // a vector of strings.
auto addEnding(std::vector<std::string> const& src,
               std::string const&              sfx) -> std::vector<std::string> {
    std::vector<std::string> result(src.size(), "");
    int                      index{0};
    for(const auto& s : src) {
        result[index] += s;
        result[index] += sfx;
        index++;
    }
    return result;
}

// //  5. Difference of Max and Min Numbers in Array
// //  Create a function that takes a vector of integers and returns the
// // difference between the smallest and biggest numbers.
auto differenceMaxMin(std::vector<int> const& src) -> int {
    int result{};
    if(src.size() < 2)
        return result;
    std::vector<int> temp;
    for(size_t i = 0; i < src.size(); i++) {
        temp.push_back(src[i]);
    }
    sort(temp.begin(), temp.end());
    result = temp.back() - temp.front();
    return result;
}
