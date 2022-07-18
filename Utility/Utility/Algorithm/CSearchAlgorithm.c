//
//  CSearchAlgorithm.c
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#include "CSearchAlgorithm.h"

int binarySearch(int *nums, int count, int target) {
    int left = 0;
    int right = count - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}
