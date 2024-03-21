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

int height(TreeNode *node) {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

void updateHeight(TreeNode *node) {
    int lh = height(node->left);
    int rh = height(node->right);
    if (lh > rh) {
        node->height = lh + 1;
    } else {
        node->height = rh + 1;
    }
}

int balanceFactor(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

TreeNode *rightRotate(TreeNode *node) {
    TreeNode *child, *grandChild;
    child = node->left;
    grandChild = child->right;
    child->right = node;
    node->left = grandChild;
    updateHeight(node);
    updateHeight(child);
    return child;
}

TreeNode *leftRotate(TreeNode *node) {
    TreeNode *child, *grandChild;
    child = node->right;
    grandChild = child->left;
    child->left = node;
    node->right = grandChild;
    updateHeight(node);
    updateHeight(child);
    return child;
}

/*
怎么判断哪种失衡类型
1. 先判断是左偏树还是右偏树
    1.1. 失衡因子 > 1 就是左偏树，左边高
    1.2. 失衡因子 < -1 就是右偏树，右边高
2. 在判断子节点的失衡因子
    2.1. 左偏树判断左节点的失衡因子，>=0 右旋
    2.2. 左偏树判断左节点的失衡因子，<0 先左旋，再右旋
    2.3. 右偏树判断右节点的失衡因子，>=0 左旋
    2.4. 右偏树判断右节点的失衡因子，<0 先右旋，再左旋
*/
TreeNode *rotate(TreeNode *node) {
    int bf = balanceFactor(node);
    if (bf > 1) {
        if (balanceFactor(node->left) >= 0) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (bf < -1) {
        if (balanceFactor(node->right) >= 0) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

