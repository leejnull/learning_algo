#include "binary_tree_dfs.h"

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
    inOrder(root->left, size, arr);
    arr[(*size)++] = root->val;
    inOrder(root->right, size, arr);
}

// 后序遍历
void postOrder(TreeNode *root, int *size, int *arr) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left, size, arr);
    postOrder(root->right, size, arr);
    arr[(*size)++] = root->val;
}
