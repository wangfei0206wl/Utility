//
//  CLinkList.h
//  Utility
//
//  Created by 王飞 on 2022/9/7.
//

#ifndef CLinkList_h
#define CLinkList_h

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// 单向链接node定义
typedef struct LinkNode {
    int value;
    struct LinkNode *next;
} CLinkNode;

// 判断单向链接是否有环
bool isCircleLinkList(CLinkNode *linkList);

// 获得单向链表环入口节点
CLinkNode *findCircleEnterNode(CLinkNode *linkList);

#ifdef __cplusplus
}    // extern "C"
#endif

#endif /* CLinkList_h */
