//
//  RecentCounter.h
//  Utility
//
//  Created by 王飞 on 2022/5/6.
//

#ifndef RecentCounter_h
#define RecentCounter_h

#include <stdio.h>

typedef struct {
    int *queue;
    int capability;
    int head;
    int tail;
} RecentCounter;

RecentCounter *recentCounterCreate(void);
int recentCounterPing(RecentCounter *obj, int t);
void recentCounterFree(RecentCounter *obj);

#endif /* RecentCounter_h */
