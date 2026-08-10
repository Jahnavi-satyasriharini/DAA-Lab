#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node* insert(struct node* root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node* deleteNode(struct node* root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("BST created successfully.\n");

    root = deleteNode(root, 30);

    printf("Node 30 deleted successfully.\n");

    return 0;
}