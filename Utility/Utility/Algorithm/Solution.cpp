//
//  Solution.cpp
//  Utility
//
//  Created by 王飞 on 2022/4/21.
//

#include "Solution.hpp"

string Solution::longestPalindrome(string s) {
    int start = 0, end = 0;
    
    for (int i = 0; i < s.size(); i++) {
        auto [left1, right1] = expandAroundCenter(s, i, i);
        auto [left2, right2] = expandAroundCenter(s, i, i + 1);
        
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    
    return s.substr(start, end - start + 1);
}

int Solution::maxRotateFunction(vector<int>& nums) {
    int res = 0;
    
    return res;
}

void Solution::func() {
    printf("hello");
}

pair<int, int> Solution::expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return {left + 1, right - 1};
}
