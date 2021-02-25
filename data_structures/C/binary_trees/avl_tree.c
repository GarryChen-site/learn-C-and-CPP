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

avlNode *minNode(avlNode *node)
{
    avlNode *temp = node;
    while (temp->left !=NULL)
        temp = temp->left;
    return temp;
}

void printAVL(avlNode *node, int level)
{

}

