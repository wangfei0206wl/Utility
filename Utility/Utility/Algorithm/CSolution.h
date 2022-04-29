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

#ifdef __cplusplus
}    // extern "C"
#endif

#endif /* CSolution_h */
