#include "../binary_tree/binary_tree_dfs.h"
#include "../utils/log.h"

void dfs(TreeNode* node, int *preorder, int i, int *inorder, int l, int r) {
    if (l > r) {
        return;
    }
    int rootVal = preorder[i];
    int m = l;
    for (; m <= r; m++) {
        if (rootVal == inorder[m]) {
            break;
        }
    }
    node->val = rootVal;
    if (m > l) {
        TreeNode *leftNode = malloc(sizeof(TreeNode));
        node->left = leftNode;
        dfs(leftNode, preorder, i+1, inorder, l, m-1);
    }
    if (m < r) {
        TreeNode *rightNode = malloc(sizeof(TreeNode));
        node->right = rightNode;
        dfs(rightNode, preorder, i+1+m-l, inorder, m+1, r);
    }
}

TreeNode *buildTree(int *preorder, int *inorder, int inorderSize) {
    // 找出顶点，左子树，右子树
    TreeNode *node = malloc(sizeof(TreeNode));
    dfs(node, preorder, 0, inorder, 0, inorderSize - 1);    
    return node;
}

int main() {
    int preorder[] = {3,9,2,1,7};
    int inorder[] = {9,3,1,2,7};
    TreeNode *node = buildTree(preorder, inorder, 5);
    int *arr = malloc(sizeof(int) * 5);
    int *size = malloc(sizeof(int));
    preOrder(node, size, arr);
    printIntArray(arr, 5);
    *size = 0;
    inOrder(node, size, arr);
    printIntArray(arr, 5);
    *size = 0;
    postOrder(node, size, arr);
    printIntArray(arr, 5);
    return 1;
}
