//
//  CSearchAlgorithm.h
//  Utility
//
//  Created by 王飞 on 2022/7/18.
//

#ifndef CSearchAlgorithm_h
#define CSearchAlgorithm_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

// 二分查找(nums为升序排序整数数组)
int binarySearch(int *nums, int count, int target);

#ifdef __cplusplus
}    // extern "C"
#endif

#endif /* CSearchAlgorithm_h */
