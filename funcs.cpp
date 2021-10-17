//https://contest.yandex.ru/contest/29396/problems/

#include "funcs.h"
#include <bits/stdc++.h>

/*! @brief First argument, that returns true for given func
 *
 * @tparam Func function pointer, lambda, on given vector should have
 * that form: "___---"
 * @param func function pointer, lambda, that should accept int as input
 * @param left Left limit
 * @param right Right limit
 * @param tol Tolerance
 * @return value
 */
template<typename Func>
int indexOfFirst(Func func, int left, int right){
    while (left<right){
        int middle = (left+right)/2;
        if(func(middle)){
            right = middle;
        } else {
            left = middle+1;
        }
    }
    return left;
}

/*! @brief Index of last element, that returns true for given func
 *
 * @tparam Func function pointer, lambda, on given vector should have
 * that form: "---____"
 * @tparam T type of values stored in vector
 * @param func function pointer, lambda, that should accept int as input
 * @param left First index, default 0
 * @param right Last index, default -1 means length of given vector
 * @return index,that you should check again
 */
template<typename Func>
int indexOfLast(Func func, int left, int right){
    while (left<right){
        int middle = (left+right+1)/2;
        if(func(middle)){
            left = middle;
        } else {
            right = middle -1;
        }
    }
    return left;
}

void parseInput(std::istream & input,
                 std::vector<std::pair<int, int> > & lines,
                 std::vector<int> & kittens,
                 int & kittensN, int & linesM){
    input>>kittensN>>linesM;

    kittens.reserve(kittensN);
    std::copy_n(std::istream_iterator<int>(input),
                kittensN,
                std::back_inserter(kittens));

    lines.reserve(linesM);
    int left, right;
    for(int i = 0; i < linesM; ++i){
        input >> left >> right;
        lines.emplace_back(left,right);
    }
}

void parseFile(std::istream & input, std::ostream & output){
    std::vector<std::pair<int,int>> lines;
    std::vector<int> kittens;
    int kittensN, linesM;
    parseInput(input,lines,kittens, kittensN, linesM);

    std::sort(kittens.begin(), kittens.end());

    std::vector<int> kittensPerLine(linesM);
    for(int i = 0; i < linesM; ++i){
        int left = lines[i].first;
        int right = lines[i].second;

        if(left > kittens.back() || right < kittens[0]){
            continue;
        }

        int firstKittenIndex = indexOfFirst(
                [&kittens, &left](int i){
                    return kittens[i]>=left;
                    },
                0, kittensN-1);
        if(kittens[firstKittenIndex] < left)
            continue;

        int lastKittenIndex = indexOfLast(
                [&kittens, &right](int i){
                    return kittens[i]<=right;
                },
                firstKittenIndex, kittensN-1);
        if(kittens[lastKittenIndex]>right)
            continue;
        kittensPerLine[i] = 1 + lastKittenIndex - firstKittenIndex;
    }

    //output
    std::copy(kittensPerLine.begin(), kittensPerLine.end(), std::ostream_iterator<int>(output, " "));
    output << std::endl;
}
