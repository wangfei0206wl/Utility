//
//  CSolution.h
//  Utility
//
//  Created by 王飞 on 2022/4/22.
//

#ifndef CSolution_h
#define CSolution_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

char *longestPalindrome(char *s);

int maxRotateFunction(int *nums, int numsSize);

int* sortArrayByParity(int* nums, int numsSize, int* returnSize);

int reverse(int x);

char *stringzconvert(char * s, int numRows);

char * stringMultiply(char *num1, char *num2);

int addDigits(int num);

char * binaryAddFunction(char *num1, char *num2);

int divideCoreFunction(int divident, int divisor);

// 字符串数组中不相同字符串(只考虑小写英文字母)的最大乘积
int maxProduct(char *string[], int size);

// 升序排序的整数数组中查找两数之和等于target的两数的下标并返回
int *sumNum(int *nums, int count, int target);

#ifdef __cplusplus
}    // extern "C"
#endif

#endif /* CSolution_h */
