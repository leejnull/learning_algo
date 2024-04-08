#include <stdio.h>
#include "build_tree.h"

/*
在二叉树中搜索所有值为 7 的节点，请返回根节点到这些节点的路径。
*/

TreeNode *path[7];
TreeNode *res[7][7];
int pathSize = 0;
int resSize = 0;

void preOrderII(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    path[pathSize++] = root;
    if (root->val == 7) {
        for (int i = 0; i < pathSize; i++) {
            res[resSize][i] = path[i];
        }
        resSize++;
    }
    preOrderII(root->left);
    preOrderII(root->right);
    // 回退
    pathSize--;
}

int main() {
    int preorder[7] = {1, 7, 4, 5, 3, 6, 7};
    int inorder[7] = {4, 7, 5, 1, 6, 3, 7};    
    TreeNode *root = buildTree(preorder, inorder, 7);
    preOrderII(root);

    printf("%d", resSize);
    for (int i = 0; i < resSize; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", res[i][j]->val);
        }
        printf("\n");
    }

    return 0;
}
