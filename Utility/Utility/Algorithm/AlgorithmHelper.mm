//
//  AlgorithmHelper.m
//  Utility
//
//  Created by 王飞 on 2022/4/21.
//

#import "AlgorithmHelper.h"
#include "Solution.hpp"

@implementation AlgorithmHelper

+ (void)test {
    Solution s;
    string test = "abccba";
    string str = s.longestPalindrome(test);
    
    printf("%s longest palindrome string: %s", test.c_str(), str.c_str());
}

@end
