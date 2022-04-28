//
//  CQueue.h
//  Utility
//
//  Created by 王飞 on 2022/4/28.
//

#ifndef CQueue_h
#define CQueue_h

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SIZE 128
typedef struct Tree *BitTree;

typedef struct Queue {
    int front;
    int rear;
    BitTree data[MAX_SIZE];
} SqQueue;

void initQueue(SqQueue **q);
bool emptyQueue(SqQueue *q);
bool enQueue(SqQueue *q, BitTree node);
bool deQueue(SqQueue *q, BitTree *node);

#ifdef __cplusplus
}    // extern "C"
#endif

#endif /* CQueue_h */
