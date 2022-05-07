//
//  CBitTree.c
//  Utility
//
//  Created by 王飞 on 2022/4/28.
//

#include "CBitTree.h"
#include <stdlib.h>
#include <stdbool.h>
#include "CQueue.h"

BitTree createSampleTree(void);
BitTree createTreeNode(BitTree root, int value, bool bLeft);

BitTree createLink(void) {
#if 0
    int data;
    int temp;
    BitTree t;
    
    scanf("%d", &data);
    temp = getchar();
    
    if (data == -1) {
        return NULL;
    } else {
        t = (BitTree)malloc(sizeof(Tree));
        t->data = data;
        
        printf("请输入%d的左子树:", data);
        t->lchild = createLink();
        printf("请输入%d的右子树:", data);
        t->rchild = createLink();
        return t;
    }
#endif
    return createSampleTree();
}

void showPreOrderTree(BitTree tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->data);
    showPreOrderTree(tree->lchild);
    showPreOrderTree(tree->rchild);
}

void showMidOrderTree(BitTree tree) {
    if (tree == NULL) {
        return;
    }
    showMidOrderTree(tree->lchild);
    printf("%d ", tree->data);
    showMidOrderTree(tree->rchild);
}

void showPostOrderTree(BitTree tree) {
    if (tree == NULL) {
        return;
    }
    showPostOrderTree(tree->lchild);
    showPostOrderTree(tree->rchild);
    printf("%d ", tree->data);
}

void showlevelOrderTree(BitTree tree) {
    SqQueue *queue;
    initQueue(&queue);
    
    if (tree) {
        enQueue(queue, tree);
    }

    BitTree tmpNode = NULL;
    
    while (!emptyQueue(queue)) {
        deQueue(queue, &tmpNode);
        printf("%d ", tmpNode->data);
        
        if (tmpNode->lchild != NULL) {
            enQueue(queue, tmpNode->lchild);
        }
        if (tmpNode->rchild != NULL) {
            enQueue(queue, tmpNode->rchild);
        }
    }
}

BitTree createSampleTree(void) {
    BitTree t = createTreeNode(NULL, 10, false);
    
    BitTree left = createTreeNode(t, 9, true);
    BitTree right = createTreeNode(t, 11, false);
    
    BitTree left1 = createTreeNode(left, 7, true);
    BitTree right1 = createTreeNode(left, 8, false);
    
    BitTree left2 = createTreeNode(right, 12, true);
    BitTree right2 = createTreeNode(right, 13, false);

    return t;
}

BitTree createTreeNode(BitTree root, int value, bool bLeft) {
    BitTree node = (BitTree)malloc(sizeof(Tree));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;

    if (root) {
        if (bLeft) {
            root->lchild = node;
        } else {
            root->rchild = node;
        }
    }
    
    return node;
}
