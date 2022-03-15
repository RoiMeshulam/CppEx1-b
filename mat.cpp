#include "mat.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string ariel::mat(int a, int b, char c1, char c2) {
    //constant values represent legitimate input values (for c1,c2)
    int const MAX_VALUE=126;
    int const MIN_VALUE=33;

    //handle improper input
    if( a % 2 == 0 || b % 2 == 0){
        throw std::invalid_argument("Mat size is always odd!");
    }
    if(a<=0||b<=0){
        throw std::invalid_argument("Mat size has to be positive!");
    }
    if (c1<MIN_VALUE||c1>MAX_VALUE||c2<MIN_VALUE||c2>MAX_VALUE){
        throw std::invalid_argument("Invalid value was entered");
    }

    //variables
    int i=0;
    int j=0;
    int right=a;
    int down=b;
    int left=0;
    int up=0;
    int numOfIter=0;
    int min=0;
    int flag=0;
    std::string s;

    // creating an empty matrix represents the rug
    vector<vector<char> > vec;
    for (int i = 0; i < b ; i++) {
        vector<char> v1;
        v1.resize(a);
        vec.push_back(v1);
    }

    // fill the matrix
    min= std::min(a,b);
    if (min%2==0){
        numOfIter=min/2;
    }else{
        numOfIter=(min/2)+1;
    }
    while (i!=numOfIter && j!=numOfIter){
        int k=i;
        int m=j;
        while (k == up && m < right){
            if (flag==0){
                vec.at(k).at(m)=c1;
                m++;
            }else{
                vec.at(k).at(m)=c2;
                m++;
            }
        }
        k++;
        m--;
        while (k<down && m==right-1){
            if (flag==0){
                vec.at(k).at(m)=c1;
                k++;
            }else{
                vec.at(k).at(m)=c2;
                k++;
            }
        }
        m--;
        k--;
        while (k==down-1 && m >=left){
            if (flag==0){
                vec.at(k).at(m)=c1;
                m--;
            }else{
                vec.at(k).at(m)=c2;
                m--;
            }
        }
        m++;
        k--;
        while (k>=up && m==left){
            if (flag==0){
                vec.at(k).at(m)=c1;
                k--;
            }else{
                vec.at(k).at(m)=c2;
                k--;
            }
        }
        if (flag==0){
            flag=1;
        }
        else{
            flag=0;
        }
        i++,j++;
        right--,down--;
        up++,left++;
    }

    // convert the mat to string
    for (int t = 0; t < vec.size() ; t++) {
        for (int r = 0; r <vec.at(t).size() ; r++) {
            s+= vec.at(t).at(r);
        }
        if (t!=vec.size()-1){
            s+='\n';
        }
    }
    return s;
}
