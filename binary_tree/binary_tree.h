#include <stdlib.h>

typedef struct TreeNode {
    int val;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newTreeNode(int val);
