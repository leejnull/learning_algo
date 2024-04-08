#include "build_tree.h"

#define MAX_SIZE 128

void dfs(TreeNode* node, int *preorder, int i, int *inorder, int l, int r) {
    if (l > r) {
        return;
    }
    int rootVal = preorder[i];
    int m = l;
    // 这个查找每次递归都要查找一遍，我们可以把对应的值映射到Map中去，见dfsPlus函数
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

TreeNode *dfsPlus(int *preorder, int *inorderMap, int i, int l, int r, int size) {
    if (l > r) {
        return NULL;
    }
    TreeNode *root = malloc(sizeof(TreeNode));
    root->val = preorder[i];
    root->left = NULL;
    root->right = NULL;
    int m = inorderMap[preorder[i]];
    root->left = dfsPlus(preorder, inorderMap, i+1, l, m-1, size);
    root->right = dfsPlus(preorder, inorderMap, i+1+m-l, m+1, r, size);
    return root;
}

TreeNode *buildTreePlus(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    // 初始化哈希表，存储 inorder 元素到索引的映射
    int *inorderMap = malloc(sizeof(int) * MAX_SIZE);
    for (int i = 0; i < inorderSize; i++) {
        inorderMap[inorder[i]] = i;
    }
    TreeNode *root = dfsPlus(preorder, inorderMap, 0, 0, inorderSize-1, inorderSize);
    free(inorderMap);
    return root;
}
