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
    
#if 0
    [AlgorithmHelper cLongestPalindromeTest];
#endif
    
#if 0
    [AlgorithmHelper maxRotateFuncTest];
#endif
    
#if 1
    [AlgorithmHelper sortArraybyParityTest];
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

+ (void)maxRotateFuncTest {
    int nums[] = {4,3,2,6};
    int max = maxRotateFunction(nums, sizeof(nums) / sizeof(int));
    
    printf("maxRotateFuncTest value: %d", max);
}

+ (void)sortArraybyParityTest {
    int nums[] = {3, 1, 2, 4};
    int size = sizeof(nums) / sizeof(int);
    int returnSize = 0;
    
    int *resultNums = sortArrayByParity(nums, size, &returnSize);
    
    printf("returnSize: %d", returnSize);
}

@end
