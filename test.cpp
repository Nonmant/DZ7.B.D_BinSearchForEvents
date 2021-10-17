#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<"3 1\n"
                  "1 2 3\n"
                  "0 1";
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();
    
    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() == "1 \n");
}

TEST_CASE("file 013", ""){
    BENCHMARK("Largest file"){
        std::ifstream input( "../013", std::ofstream::in);
        std::stringstream output;
        parseFile(input,output);
        input.close();

        std::ifstream answer("../013.a", std::ofstream::in);
        std::string answerStr(std::istreambuf_iterator<char>{answer}, {});
        answer.close();
        REQUIRE(output.str() == answerStr);
    };
}

TEST_CASE("one, contains all", ""){
    std::stringstream input, output;
    input<<"3 1\n"
           "1 2 3\n"
           "0 4";
    parseFile(input,output);
    REQUIRE(output.str() == "3 \n");
}

TEST_CASE("one, contains none, in the middle", ""){
    std::stringstream input, output;
    input<<"3 1\n"
           "1 4 5\n"
           "2 3";
    parseFile(input,output);
    REQUIRE(output.str() == "0 \n");
}

TEST_CASE("one, contains none, larger", ""){
    std::stringstream input, output;
    input<<"3 1\n"
           "1 4 5\n"
           "6 7";
    parseFile(input,output);
    REQUIRE(output.str() == "0 \n");
}

TEST_CASE("one, contains none, smaller", ""){
    std::stringstream input, output;
    input<<"3 1\n"
           "1 4 5\n"
           "-1 0";
    parseFile(input,output);
    REQUIRE(output.str() == "0 \n");
}

TEST_CASE("one, zero length, contains none", ""){
    std::stringstream input, output;
    input<<"3 1\n"
           "1 4 5\n"
           "2 2";
    parseFile(input,output);
    REQUIRE(output.str() == "0 \n");
}

TEST_CASE("one, zero length, contains all", ""){
    std::stringstream input, output;
    input<<"3 1\n"
           "4 4 4\n"
           "4 4";
    parseFile(input,output);
    REQUIRE(output.str() == "3 \n");
}

TEST_CASE("two, zero length, contains all", ""){
    std::stringstream input, output;
    input<<"3 2\n"
           "4 4 4\n"
           "4 4"
           "4 4";
    parseFile(input,output);
    REQUIRE(output.str() == "3 3 \n");
}
