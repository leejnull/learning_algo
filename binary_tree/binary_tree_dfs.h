#ifndef BINARY_TREE_DFS_H
#define BINARY_TREE_DFS_H

#include "binary_tree.h"

void preOrder(TreeNode *root, int *size, int *arr);
void inOrder(TreeNode *root, int *size, int *arr);
void postOrder(TreeNode *root, int *size, int *arr);

#endif