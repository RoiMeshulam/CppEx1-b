#include "mat.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include "doctest.h"
using namespace ariel;

TEST_CASE("Good input") {
    CHECK(mat(1,1,'a','b')=="a");
    CHECK(mat(3,3,'a','b')=="aaa\naba\naaa");
    CHECK(mat(5,5,'a','b')=="aaaaa\nabbba\nababa\nabbba\naaaaa");
    CHECK(mat(1,3,'1','0')=="1\n1\n1");
    CHECK(mat(3,1,'1','0')=="111");
    CHECK(mat(1,5,'@','-')=="@\n@\n@\n@\n@");
    CHECK(mat(5,3,'@','-')=="@@@@@\n@---@\n@@@@@");
}
TEST_CASE("Good Long input") {
    CHECK(mat(11,11,'a','b')=="aaaaaaaaaaa\nabbbbbbbbba\nabaaaaaaaba\nababbbbbaba\nababaaababa\nabababababa\nababaaababa\nababbbbbaba\nabaaaaaaaba\nabbbbbbbbba\naaaaaaaaaaa");
    CHECK(mat(31,3,'a','b')=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\nabbbbbbbbbbbbbbbbbbbbbbbbbbbbba\naaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    CHECK(mat(17,13,'a','b')=="aaaaaaaaaaaaaaaaa\nabbbbbbbbbbbbbbba\nabaaaaaaaaaaaaaba\nababbbbbbbbbbbaba\nababaaaaaaaaababa\nabababbbbbbbababa\nabababaaaaabababa\nabababbbbbbbababa\nababaaaaaaaaababa\nababbbbbbbbbbbaba\nabaaaaaaaaaaaaaba\nabbbbbbbbbbbbbbba\naaaaaaaaaaaaaaaaa");
}



TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(2, 2, '1', '0'));
    CHECK_THROWS(mat(5, 10, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));
    CHECK_THROWS(mat(0, 5, 'a', 'b'));
    CHECK_THROWS(mat(-10, 5, '$', '%'));
    CHECK_THROWS(mat(10, -5, '$', '%'));
    CHECK_THROWS(mat(-10, -5, '$', '%'));
    CHECK_THROWS(mat(0, -5, '$', '%'));
    CHECK_THROWS(mat(-10, 0 , '$', '%'));
}
