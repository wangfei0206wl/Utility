//
//  Solution.hpp
//  Utility
//
//  Created by 王飞 on 2022/4/21.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    Solution() {}
    ~Solution() {}
    
    string longestPalindrome(string s);
    int maxRotateFunction(vector<int>& nums);
    static void func();
    
private:
    pair<int, int> expandAroundCenter(const string& s, int left, int right);
};

#endif /* Solution_hpp */
