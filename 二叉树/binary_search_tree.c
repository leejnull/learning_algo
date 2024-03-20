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

