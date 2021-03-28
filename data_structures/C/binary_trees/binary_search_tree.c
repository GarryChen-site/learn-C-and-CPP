
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

int height(node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    else
    {
        int right_h = height(root->right);
        int left_h = height(root->left);

        // The final height is the height of the greatest subtree(left or right)
        // plus 1 (which is the root's level)
        if(right_h > left_h)
        {
            return (right_h + 1);
        }
        else
        {
            return (left_h + 1);
        }
    }
}

void purge(node *root)
{
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            purge(root->left);
        }
        if(root->right != NULL)
        {
            purge(root->right);
        }
        free(root);
        root = NULL; // reset pointer
    }
}

void inOrder(node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("\t[ %d ]\t",root->data);
        inOrder(root->right);
    }
}
/**
 * 返回值是调整后的root
 */
node *delete(node *root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    else if(data > root->data)
    {
        root->right = delete(root->right,data);
    }
    else if(data < root->data)
    {
        root->left = delete(root->left,data);
    }
    // 遍历到某个节点等于需要删除的data
    else if (data == root->data)
    {
        if((root->left == NULL) && (root->right == NULL))
        {
            // Case 1: the root has no leaves, remove the node
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            // Case 2: the root has one leaf, make the lead the new root and
            // remove
            node *tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
        else if(root->right == NULL)
        {
            node *tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
        else
        {
            // todo 
            // Case 3: the root has 2 leaves, find the greatest key in the left
            // subtree and switch with root's

            // finds the biggest node in the left branch
            node *tmp = getMax(root->left);

            // sets the data of this node equal to the data of the biggest node
            root->data = tmp->data;
            root->left = delete(root->left, tmp->data);
        }
    }
    return root;
}