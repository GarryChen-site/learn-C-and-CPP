//
// Created by  雨下的文 on 2021/2/25.
//

#include <stdio.h>
#include <stdlib.h>

struct AVLnode
{
    int key;
    struct AVLnode *left;
    struct AVLnode *right;
    int height;
};
typedef struct AVLnode avlNode;

int max(int a, int b)
{
    return (a > b) ? a: b;
}

avlNode *newNode(int key)
{
    avlNode *node = (avlNode *)malloc(sizeof(avlNode));

    if(node == NULL)
        printf("!! Out of Space !!\n");
    else
    {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }
    return node;
}

int nodeHeight(avlNode *node)
{
    if(node ==NULL)
        return -1;
    else
        return (node->height);
}

int heightDiff(avlNode *node)
{
    if (node == NULL)
        return 0;
    else
        return (nodeHeight(node->left) - nodeHeight(node->right));
}

// 给定avlNode的最小值
avlNode *minNode(avlNode *node)
{
    avlNode *temp = node;
    while (temp->left !=NULL)
        temp = temp->left;
    return temp;
}

void printAVL(avlNode *node, int level)
{
    int i;
    if(node != NULL)
    {
        printAVL(node->right, level + 1);
        printf("\n\n");

        for(i=0; i<level;i++)
        {
            printf("\t");
        }
        printf("%d",node->key);
        printAVL(node->left, level+1);
    }
}

avlNode *leftRotate(avlNode *z)
{
    avlNode *y = z->right;
    avlNode *T3 = y->left;

    y->left = z;
    z->right = T3;

    z->height = (max(nodeHeight(z->left),nodeHeight(z->right)) + 1);
    y->height = (max(nodeHeight(y->left),nodeHeight(y->right)) + 1);

    return y;
}
// 考虑相对位置
// insert 3 2 1
avlNode *rightRotate(avlNode *z)
{
    avlNode *y = z->left;
    avlNode *T3 = y->right;

    y->right = z; // 是y的right等于z，不是z等于y->right
    z->left = T3;

    z->height = (max(nodeHeight(z->left),nodeHeight(z->right)) + 1);
    y->height = (max(nodeHeight(y->left),nodeHeight(y->right)) + 1);

    return y;
}

//insert 3 1 2
avlNode *LeftRightRotate(avlNode *z)
{

}
