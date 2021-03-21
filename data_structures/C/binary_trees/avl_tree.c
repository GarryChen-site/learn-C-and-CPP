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
// left - right
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

// insert 1 2 3 *z is root of subtree to be rotated left .Here is 3. Return new root of rebalanced subtree
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

// a rotation always balances the tree
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
    // retracing
    // node height as per the AVL formula
    node->height = (max(nodeHeight(node->left), nodeHeight(node->right)) + 1);

    // checking for the balance condiion
    int balance = heightDiff(node);

    // left left >1 left heavy  think shape
    if(balance > 1 && key < (node->left->key))
    {
        return rightRotate(node);
    }
    
    // right right
    if(balance < -1 && key > (node->right->key))
    {
        return leftRotate(node);
    }

    // left right
    if(balance > 1 && key > (node->left->key))
    {
        node = LeftRightRotate(node);
    }

    // right left
    if(balance < -1 && key <(node->right->key))
    {
        node = RightLeftRoate(node);
    }
    
    return node;
}

// after the appropriate single or double rotation the height of the rebalanced subtree decreases by one 
// meaning that the tree has to be rebalanced again on the next higher level
avlNode *delete(avlNode *node, int queryNum)
{
    if(node == NULL)
    {
        return node;
    }

    if(queryNum < node->key)
    {
        node->left = 
        delete(node->left, queryNum);
    }
    else if(queryNum > node->key)
    {
        node->right = 
        delete(node->right,queryNum);
    }
    else
    {
        //todo null,single, two child
    }

    if(node == NULL)
    {
        return node;
    }

    // update height
    node->height = (max(nodeHeight(node->left),nodeHeight(node->right)) + 1);

    int balance = heightDiff(node);

    
}

avlNode *findNode(avlNode *node, int queryNum)
{
    if(node != NULL)
    {
        if(queryNum < node->key)
        {
            node = findNode(node->left, queryNum);
        }
        else if (queryNum > node->key)
        {
            node = findNode(node->right, queryNum);
        }
    }
    return node;
}


void printPreOrder(avlNode *node)
{
    if(node == NULL)
    {
        return;
    }
    printf("  %d  ", (node->key));
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(avlNode *node)
{
    if(node == NULL)
    {
        return;
    }
    printInOrder(node->left);
    printf("  %d  ", (node->key));
    printInOrder(node->right);
}

void printPostOrder(avlNode *node)
{
    if(node == NULL)
    {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("  %d  ", (node->key));
}

