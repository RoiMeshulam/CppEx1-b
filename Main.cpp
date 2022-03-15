#include <iostream>
#include "mat.hpp"
#include <string>
#include <algorithm>


int main() {
    //variables
    int a,b;
    char c1,c2;
    //receive the values (a,b,c1,c2) from the user
    std::cout << "please enter two numbers for the matrix size"<<std::endl;
    std::cin >>a;
    std::cin >>b;
    std::cout << "please enter two characters"<<std::endl;
    std::cin >>c1;
    std::cin >>c2;

    string s = ariel::mat(a,b,c1,c2);
    std::cout << s << std::endl;
    return 0;
}
