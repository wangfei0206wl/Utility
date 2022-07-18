//
//  CSortAlgorithm.c
//  Utility
//
//  Created by 王飞 on 2022/7/1.
//

#include "CSortAlgorithm.h"

int partition(int *nums, int low, int high);
void quickSortPartition(int *nums, int low, int high);

void quickSort(int *nums, int count) {
    quickSortPartition(nums, 0, count - 1);
}

int partition(int *nums, int low, int high) {
    // 设立基准
    int tmp = nums[low];
    
    while (low < high) {
        // 1、从后往前找比基准小的数字进行交换
        while (low < high && nums[high] > tmp) {
            high--;
        }
        if (low < high) {
            nums[low] = nums[high];
        }
        
        // 2、从前往后找比基准大的数字进行交换
        while (low < high && nums[low] <= tmp) {
            low++;
        }
        if (low < high) {
            nums[high] = nums[low];
        }
    }
    nums[low] = tmp;
    
    return low;
}

void quickSortPartition(int *nums, int low, int high) {
    int parIndex = partition(nums, low, high);
    
    if (low < parIndex - 1) {
        quickSortPartition(nums, low, parIndex - 1);
    }
    if (parIndex + 1 < high) {
        quickSortPartition(nums, parIndex + 1, high);
    }
}
