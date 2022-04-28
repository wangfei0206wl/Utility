//
//  CQueue.c
//  Utility
//
//  Created by 王飞 on 2022/4/28.
//

#include "CQueue.h"
#include <stdlib.h>

void initQueue(SqQueue **q) {
    *q = (SqQueue *)malloc(sizeof(SqQueue));
    if (*q == NULL) {
        printf("内在分配失败");
        exit(-1);
    }
    (*q)->front = (*q)->rear = -1;
}

bool emptyQueue(SqQueue *q) {
    if (q->front == q->rear) {
        return true;
    }
    return false;
}

bool enQueue(SqQueue *q, BitTree node) {
    if (q->rear == MAX_SIZE - 1) {
        return false;
    }
    q->rear++;
    q->data[q->rear] = node;
    
    return true;
}

bool deQueue(SqQueue *q, BitTree *node) {
    if (q->front == q->rear) {
        return false;
    }
    q->front++;
    *node = q->data[q->front];
    
    return true;
}
