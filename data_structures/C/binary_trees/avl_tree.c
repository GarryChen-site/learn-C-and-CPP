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

// insert 1 2 3
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

// insert 3 2 1 ringtRotate (2) 返回的值是啥
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
    // 为右转做准备,因为2是底端，应该是中间的点来左旋，所以是leftRotate(z->left)
    // 为什么赋值给z->left 只是赋值给本来应该在中间的位置
    z->left = leftRotate(z->left);
    // z 转到中间后
    return (rightRotate(z));
}

avlNode *RightLeftRoate(avlNode *z)
{
    z->right = rightRotate(z->right);

    return (leftRotate(z));
}

avlNode *insert(avlNode *node, int key)
{
    if(node == NULL)
    {
        return (newNode(key));
    }

    // Binary Search Tree insertion
    if(key < node->left)
    {
        node -> left = insert(node->left, key);
    }
    else if(key > node->right)
    {
        node ->right = insert(node->right, key);
    }

    // node height as per the AVL formula
    node->height = (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);

    // checking for the balance condiion
    int balance = heightDiff(node);

    // left left
    
    // right right
    
    return node;
}
