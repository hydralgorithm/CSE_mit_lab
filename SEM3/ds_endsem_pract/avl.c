
#include <stdio.h>
#include <stdlib.h>

typedef struct AvlNode {
    int element;
    struct AvlNode *left, *right;
    int height;
} AvlNode;

int max(int a, int b) {
    return a > b ? a : b;
}

int height(AvlNode *root) {
    return root == NULL ? -1 : root->height;
}

AvlNode *createNode(int x) {
    AvlNode *temp = malloc(sizeof(AvlNode));
    if (temp == NULL)
        exit(1);

    temp->element = x;
    temp->left = temp->right = NULL;
    temp->height = 0;
    return temp;
}

// LL case: Right rotation
AvlNode *rotateRight(AvlNode *root) {
    AvlNode *temp = root->left;

    root->left = temp->right;
    temp->right = root;

    root->height = 1 + max(height(root->left),
                           height(root->right));
    temp->height = 1 + max(height(temp->left),
                           height(temp->right));

    return temp;
}

// RR case: Left rotation
AvlNode *rotateLeft(AvlNode *root) {
    AvlNode *temp = root->right;

    root->right = temp->left;
    temp->left = root;

    root->height = 1 + max(height(root->left),
                           height(root->right));
    temp->height = 1 + max(height(temp->left),
                           height(temp->right));

    return temp;
}

// Recursive AVL insertion
AvlNode *insert(AvlNode *root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->element)
        root->left = insert(root->left, x);
    else if (x > root->element)
        root->right = insert(root->right, x);
    else
        return root;

    // Update height
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int bf = height(root->left) - height(root->right);

    // LL
    if (bf > 1 && x < root->left->element)
        return rotateRight(root);

    // RR
    if (bf < -1 && x > root->right->element)
        return rotateLeft(root);

    // LR
    if (bf > 1 && x > root->left->element) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL
    if (bf < -1 && x < root->right->element) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Inorder traversal
void inorder(AvlNode *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->element);
    inorder(root->right);
}

int main() {
    AvlNode *root = NULL;

    int arr[] = {30, 20, 40, 10, 25, 35, 50, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}
