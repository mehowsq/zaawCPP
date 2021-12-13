#include <iostream>
#include <string>
#include <vector>
#include "a.h"

int main() {
    A a("aaaBBBccc");
    A b(a);

    std::vector<A> vec;
    vec.push_back(A{"aaa"});
    vec.push_back(A{"bbb"});
    vec.push_back(A{"ccc"});

}