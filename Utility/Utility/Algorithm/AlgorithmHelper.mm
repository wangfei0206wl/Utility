//
//  AlgorithmHelper.m
//  Utility
//
//  Created by 王飞 on 2022/4/21.
//

#import "AlgorithmHelper.h"
#include "Solution.hpp"
#import "CSolution.h"

@implementation AlgorithmHelper

+ (void)test {
    
#if 0
    [AlgorithmHelper cppLongestPalindromeTest];
#endif
    
#if 1
    [AlgorithmHelper cLongestPalindromeTest];
#endif
    
}

+ (void)cppLongestPalindromeTest {
    Solution s;
    string test = "abccba";
    string str = s.longestPalindrome(test);
    
    printf("%s longest palindrome string: %s", test.c_str(), str.c_str());
}

+ (void)cLongestPalindromeTest {
    char test[] = "babad";
    char *res = longestPalindrome(test);
    
    printf("%s longest palindrome string: %s", test, res);
}

@end
