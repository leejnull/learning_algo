#include "../binary_tree/binary_tree.h"

/*
给定一棵二叉树，搜索并记录所有值为7的节点，请返回节点列表。
*/

void preOrder(TreeNode *root, TreeNode **res, int *resSize) {
    if (root == NULL) {
        return;
    }
    if (root->val == 7) {
        res[*resSize++] = root;
    }
    preOrder(root->left, res, resSize);
    preOrder(root->right, res, resSize);
}
