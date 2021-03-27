
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
}node;

node *newNode(int data)
{
    node *tmp = (node *)malloc(sizeof(node));

    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

node *insert(node *root, int data)
{
    if(root ==NULL)
    {
        root = newNode(data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right,data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left,data);
    }
    return root;
}

node *getMax(node *root)
{
    if(root->right != NULL)
    {
        return getMax(root->right);
    }
    return root;
}

int find(node *root, int data)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(data > root->data)
    {
        return find(root->right,data);
    }
    else if(data < root->data)
    {
        return find(root->left,data);
    }
    else if(data == root->data)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}