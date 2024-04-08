#ifndef BUILD_TREE_H
#define BUILD_TREE_H

#include "../binary_tree/binary_tree.h"

TreeNode *buildTree(int *preorder, int *inorder, int inorderSize);
TreeNode *buildTreePlus(int *preorder, int preorderSize, int *inorder, int inorderSize);

#endif