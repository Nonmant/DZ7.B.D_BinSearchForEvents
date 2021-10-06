//https://contest.yandex.ru/contest/29396/problems/

#include "funcs.h"
#include <bits/stdc++.h>

enum EventType : short int{
    LineStart = 0,
    Kitten = 1,
    LineEnd = 2
};

struct Line{
    int left, right, kittens = 0;
    Line(int left, int right):
        left(left),right(right){}
};

void parseInput(std::istream & input,
                 std::vector<std::tuple<int, EventType, int> > & events,
                 std::vector<Line> & lines,
                 int & kittensN, int & linesM){
    events.clear();
    lines.clear();

    input>>kittensN>>linesM;

    events.reserve(kittensN+2*linesM);
    lines.reserve(linesM);

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
        lines.emplace_back(left,right);
    }
}

void parseFile(std::istream & input, std::ostream & output){
    //! position, type, index of line
    std::vector<std::tuple<int, EventType, int> > events;
    std::vector<Line> lines;
    int kittensN, linesM;
    parseInput(input,events,lines, kittensN, linesM);

    std::sort(events.begin(), events.end());

    std::unordered_set<int> curLines;
    for(auto & event : events){
        auto [pos, type, lineIndex] = event;
        switch (type) {
            case LineStart:
                curLines.insert(lineIndex);
                break;
            case LineEnd:
                curLines.erase(lineIndex);
                break;
            case Kitten:
                for(auto i : curLines){
                    ++lines[i].kittens;
                }
                break;
        }
    }

    //output
    for(auto & line : lines){
        output << line.kittens << ' ';
    }
    output << std::endl;
}
