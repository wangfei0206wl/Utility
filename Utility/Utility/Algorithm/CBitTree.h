//
//  CBitTree.h
//  Utility
//
//  Created by 王飞 on 2022/4/28.
//

#ifndef CBitTree_h
#define CBitTree_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Tree {
    int data;
    struct Tree *lchild;
    struct Tree *rchild;
}Tree, *BitTree;

BitTree createLink(void);
void showPreOrderTree(BitTree tree);
void showMidOrderTree(BitTree tree);
void showPostOrderTree(BitTree tree);
void showlevelOrderTree(BitTree tree);

#ifdef __cplusplus
}    // extern "C"
#endif

#endif /* CBitTree_h */
