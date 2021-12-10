#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../parser.h"
#include "../graph.h"
#include "../pagerank.h"
#include <unordered_map>
#include <iostream>

// Double comparision helper function
bool areEqual(double a, double b) {
    return fabs(a - b) < 0.001;
}

// TODO: Delete this after you complete at least 1 test case, else Makefile linker will break
TEST_CASE("Foo") {
    REQUIRE(1==1);
}

TEST_CASE("Simple PageRank, 1 iteration") {
    Parser parseObj = Parser();
    parseObj.parseData("data/pagerank_simple.txt");
    Graph myGraph = Graph(parseObj.data_);
    PageRank p = PageRank(myGraph, 0.85, 1);
    p.rank();
    std::unordered_map<int, double> result = p.get_rank();

    // Reference: https://courses.cs.washington.edu/courses/cse373/17au/project3/project3-3.html
    REQUIRE(areEqual(result[0], 0.675));
    REQUIRE(areEqual(result[1], 0.10833));
    REQUIRE(areEqual(result[2], 0.10833));
    REQUIRE(areEqual(result[3], 0.10833));
}