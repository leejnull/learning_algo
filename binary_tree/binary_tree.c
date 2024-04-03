#include "binary_tree.h"

TreeNode *newTreeNode(int val) {
    TreeNode *node;
    
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}


