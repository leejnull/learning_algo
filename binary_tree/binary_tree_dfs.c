#include <stdlib.h>

typedef struct TreeNode {
    int val;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newTreeNode(int val) {
    TreeNode *node;
    
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 前序遍历
void preOrder(TreeNode *root, int *size, int *arr) {
    if (root == NULL) {
        return;
    }
    arr[(*size)++] = root->val;
    preOrder(root->left, size, arr);
    preOrder(root->right, size, arr);
}

// 中序遍历
void inOrder(TreeNode *root, int *size, int *arr) {
    if (root == NULL) {
        return;
    }
    preOrder(root->left, size, arr);
    arr[(*size)++] = root->val;
    preOrder(root->right, size, arr);
}

// 后序遍历
void postOrder(TreeNode *root, int *size, int *arr) {
    if (root == NULL) {
        return;
    }
    preOrder(root->left, size, arr);
    preOrder(root->right, size, arr);
    arr[(*size)++] = root->val;
}
