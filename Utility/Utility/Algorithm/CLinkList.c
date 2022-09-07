//
//  CLinkList.c
//  Utility
//
//  Created by 王飞 on 2022/9/7.
//

#include "CLinkList.h"

bool isCircleLinkList(CLinkNode *linkList) {
    CLinkNode *fast = linkList;
    CLinkNode *slow = linkList;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            return true;
        }
    }
    
    return false;
}

CLinkNode *findCircleEnterNode(CLinkNode *linkList) {
    CLinkNode *fast = linkList;
    CLinkNode *slow = linkList;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            fast = linkList;
            
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            
            return fast;
        }
    }
    
    return NULL;
}
