//https://contest.yandex.ru/contest/29396/problems/

#include "funcs.h"
#include <bits/stdc++.h>

enum EventType : short int{
    LineStart = 0,
    Kitten = 1,
    LineEnd = 2
};

void parseInput(std::istream & input,
                 std::vector<std::tuple<int, EventType, int> > & events,
                 int & kittensN, int & linesM){
    events.clear();

    input>>kittensN>>linesM;

    events.reserve(kittensN+2*linesM);

    int pos;
    for(int i = 0; i<kittensN; ++i){
        input >> pos;
        events.emplace_back(pos,Kitten,-1);
    }
    int left, right;
    for(int i = 0; i < linesM; ++i){
        input >> left >> right;
        events.emplace_back(left, LineStart, i);
        events.emplace_back(right, LineEnd, i);
    }
}

void parseFile(std::istream & input, std::ostream & output){
    //! position, type, index of line
    std::vector<std::tuple<int, EventType, int> > events;
    std::vector<std::pair<int,int>> lines;
    int kittensN, linesM;
    parseInput(input,events, kittensN, linesM);

    std::sort(events.begin(), events.end());

    std::vector<int> kittensPerLine(linesM);
    std::unordered_set<int> curLines;
    for(auto & event : events){
        switch (std::get<1>(event)) {
            case LineStart:
                curLines.insert(std::get<2>(event));
                break;
            case LineEnd:
                curLines.erase(std::get<2>(event));
                break;
            case Kitten:
                for(auto i : curLines){
                    ++kittensPerLine[i];
                }
                break;
        }
    }

    //output
    std::copy(kittensPerLine.begin(), kittensPerLine.end(), std::ostream_iterator<int>(output, " "));
    output << std::endl;
}
