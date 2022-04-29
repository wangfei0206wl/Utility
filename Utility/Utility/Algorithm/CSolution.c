//
//  CSolution.c
//  Utility
//
//  Created by 王飞 on 2022/4/22.
//

#include "CSolution.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void expandAroundCenter(char *s, int *left, int *right) {
    int len = (int)strlen(s);
    int tmpLeft = *left;
    int tmpRight = *right;
    
    while (tmpLeft >= 0 && tmpRight < len && s[tmpLeft] == s[tmpRight]) {
        tmpLeft--;
        tmpRight++;
    }
    
    *left = tmpLeft + 1;
    *right = tmpRight - 1;
}

char *longestPalindrome(char *s) {
    int start = 0, end = 0;
    int len = (int)strlen(s);
    
    for (int i = 0; i < len; i++) {
        int left1 = i, right1 = i;
        int left2 = i, right2 = i + 1;
        expandAroundCenter(s, &left1, &right1);
        expandAroundCenter(s, &left2, &right2);
        
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    int sublen = end - start + 1;
    char *tmp = (char *)malloc(sizeof(char) * (sublen + 1));
    memset(tmp, 0, sizeof(char) * (sublen + 1));
    memcpy(tmp, s + start, sublen);
    
    return tmp;
}

int maxRotateFunction(int *nums, int numsSize) {
    int f = 0, numSum = 0;
    for (int i = 0; i < numsSize; i++) {
        f += i * nums[i];
        numSum += nums[i];
    }
    int res = f;
    for (int i = numsSize - 1; i > 0; i--) {
        f += numSum - numsSize * nums[i];
        res = MAX(res, f);
    }
    
    return res;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
#if 0
    int left = 0, right = numsSize - 1;
    
    while (left < right) {
        int leftNum = nums[left];
        
        if (leftNum % 2 == 1) {
            // 奇数
            while (right > left) {
                int rightNum = nums[right];
                
                if (rightNum % 2 == 1) {
                    // 奇数
                    right--;
                } else {
                    // 偶数，交换位置
                    nums[left] = rightNum;
                    nums[right] = leftNum;
                    left++;
                    right--;
                    break;
                }
            }
        } else {
            // 偶数
            left++;
        }
    }
    
    *returnSize = numsSize;
    
    return nums;
#endif
#if 1
    int left = 0, right = numsSize - 1;
    
    while (left < right) {
        while (left < right && nums[left] % 2 == 0) {
            left++;
        }
        while (left < right && nums[right] % 2 == 1) {
            right--;
        }
        
        if (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    
    *returnSize = numsSize;
    return nums;
#endif
}

int reverse(int x) {
    int result = 0;
    
    while (x != 0) {
        if (result < INT_MIN / 10 || result > INT_MAX / 10) {
            return 0;
        }
        
        int digit = x % 10;
        result = result * 10 + digit;
        x = x / 10;
    }
    
    return result;
}

char *stringzconvert(char *s, int numRows) {
    int n = (int)strlen(s), r = numRows;
    if (r == 1 || r >= n) {
        return s;
    }
    int t = r * 2 - 2;
    char * ans = (char *)malloc(sizeof(char) * (n + 1));
    int pos = 0;
    for (int i = 0; i < r; ++i) { // 枚举矩阵的行
        for (int j = 0; j + i < n; j += t) { // 枚举每个周期的起始下标
            ans[pos++] = s[j + i]; // 当前周期的第一个字符
            if (0 < i && i < r - 1 && j + t - i < n) {
                ans[pos++] = s[j + t - i]; // 当前周期的第二个字符
            }
        }
    }
    ans[pos] = '\0';
    return ans;
}
