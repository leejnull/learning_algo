#include <stdio.h>
#include "build_tree.h"

/**
 * 在二叉树中搜索所有值为 7 的节点，请返回根节点到这些节点的路径，并要求路径中不包含值为 3 的节点。
*/

TreeNode *path[7];
TreeNode *res[7][7];
int pathSize = 0;
int resSize = 0;

void preOrder(TreeNode *root) {
    if (root == NULL || root->val == 3) {
        return;
    }
    path[pathSize++] = root;
    if (root->val == 7) {
        for (int i = 0; i < pathSize; i++) {
            res[resSize][i] = path[i];
        }
        resSize++;
    }
    preOrder(root->left);
    preOrder(root->right);
    pathSize--;
}
