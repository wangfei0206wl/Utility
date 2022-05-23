//
//  AlgorithmHelper.m
//  Utility
//
//  Created by 王飞 on 2022/4/21.
//

#import "AlgorithmHelper.h"
#include "Solution.hpp"
#include "CSolution.h"
#include "CBitTree.h"

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
    
#if 0
    [AlgorithmHelper sortArraybyParityTest];
#endif
    
#if 0
    [AlgorithmHelper reverseTest];
#endif
    
#if 0
    [AlgorithmHelper bitTreeTest];
#endif
    
#if 0
    [AlgorithmHelper zstringConvertTest];
#endif
    
#if 0
    [AlgorithmHelper stringMultiplyTest];
#endif
    
#if 0
    [AlgorithmHelper stringBinaryAddTest];
#endif
    
#if 1
    [AlgorithmHelper divideFunctionTest];
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

+ (void)reverseTest {
    int num = 310;
    int result = reverse(num);
    
    printf("num %d reverse %d", num, result);
}

+ (void)bitTreeTest {
    BitTree tree = createLink();
    printf("先序：\n");
    showPreOrderTree(tree);
    printf("\n中序：\n");
    showMidOrderTree(tree);
    printf("\n后序：\n");
    showPostOrderTree(tree);
    printf("\n层次：\n");
    showlevelOrderTree(tree);
}

+ (void)zstringConvertTest {
    char s[] = "PAYPALISHIRING";
    int numRows = 4;
    
    char *res = stringzconvert(s, numRows);
    
    printf("%s zconvert : %s", s, res);
}

+ (void)stringMultiplyTest {
    char *num1 = "2";
    char *num2 = "3";
    
    char *res = stringMultiply(num1, num2);
    
    printf("%s * %s = %s", num1, num2, res);
}

+ (void)stringBinaryAddTest {
    char *num1 = "1011001";
    char *num2 = "1000110";
    
    char *res = binaryAddFunction(num1, num2);
    
    printf("%s + %s = %s", num1, num2, res);
}

+ (void)divideFunctionTest {
    int divident = 21;
    int divisor = 7;
    int res = divideCoreFunction(divident, divisor);
    
    printf("%d / %d = %d", divident, divisor, res);
}

@end
