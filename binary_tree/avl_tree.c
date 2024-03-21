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

/*
组织和存储大型数据，适用于高频查找、低频增删的场景。
用于构建数据库中的索引系统。
红黑树也是一种常见的平衡二叉搜索树。相较于 AVL 树，红黑树的平衡条件更宽松，
插入与删除节点所需的旋转操作更少，节点增删操作的平均效率更高。
*/
typedef struct AVLTree {
    struct TreeNode *root;
} AVLTree;

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

void insert(AVLTree *tree, int val) {
    tree->root = insertHelper(tree->root, val);
}

TreeNode *insertHelper(TreeNode *node, int val) {
    if (node == NULL) {
        return newTreeNode(val);
    }
    if (val < node->val) {
        node->left = insertHelper(node->left, val);
    } else if (val > node->val) {
        node->right = insertHelper(node->right, val);
    } else {
        return node;
    }
    updateHeight(node);
    node = rotate(node);
    return node;
}

void removeItem(AVLTree *tree, int val) {
    tree->root = removeHelper(tree->root, val);
}

TreeNode *removeHelper(TreeNode *node, int val) {
    TreeNode *child, *grandChild;
    if (node == NULL) {
        return newTreeNode(val);
    }
    if (val < node->val) {
        node->left = removeHelper(node->left, val);
    } else if (val > node->val) {
        node->right = removeHelper(node->right, val);
    } else {
        if (node->left == NULL || node->right == NULL) {
            child = node->left != NULL ? node->left : node->right;
            // 子节点数量 0
            if (child == NULL) {
                return NULL;
            } else {
                // 子节点数量 1
                node = child;
            }
        } else {
            // 子节点数量 2
            TreeNode *temp = node->right;
            // 找右边的最小节点
            while (temp->left != NULL) {
                temp = temp->left;
            }
            int tempVal = temp->val;
            // 删除右边的最小节点
            node->right = removeHelper(node->right, tempVal);
            // 右边的最小节点值放在当前删除节点的位置
            node->val = tempVal;
        }
    }
    updateHeight(node);
    node = rotate(node);
    return node;
}
