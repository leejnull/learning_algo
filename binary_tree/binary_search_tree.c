#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

typedef struct BinarySearchTree {
    struct TreeNode *root;
} BinarySearchTree;

TreeNode *search(BinarySearchTree *bst, int num) {
    TreeNode *cur = bst->root;
    while (cur != NULL) {
        if (cur->val < num) {
            cur = cur->right;
        } else if (cur->val > num) {
            cur = cur->left;
        } else {
            break;
        }
    }
    return cur;
}

void insert(BinarySearchTree *bst, int num) {
    if (bst->root == NULL) {
        bst->root = newTreeNode(num);
        return;
    }
    TreeNode *cur = bst->root, *pre = NULL;
    while (cur != NULL) {
        if (cur->val == num) {
            return;
        }
        pre = cur;
        if (cur->val < num) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    TreeNode *node = newTreeNode(num);
    if (pre->val < num) {
        pre->right = node;
    } else {
        pre->left = node;
    }
}

void removeItem(BinarySearchTree *bst, int num) {
    if (bst->root == NULL) {
        return;
    }
    TreeNode *cur = bst->root, *pre = NULL;
    while (cur != NULL) {
        if (cur->val == num) {
            break;
        }
        pre = cur;
        if (cur->val < num) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    if (cur == NULL) {
        return;
    }
    if (cur->left == NULL || cur->right == NULL) {
        // 子节点数量0或1时
        TreeNode *child = cur->left != NULL ? cur->left : cur->right;
        if (pre->left == cur) {
            pre->left = child;
        } else {
            pre->right = child;
        }
        free(cur);
    } else {
        // 子节点数量是2
        TreeNode *tmp = cur->right;
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        removeItem(bst, tmp->val);
        cur->val = tmpVal;
    }
}
