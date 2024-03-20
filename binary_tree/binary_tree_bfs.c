#include <stdlib.h>

#define MAX_SIZE 128

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

// 层序遍历，通过队列实现
int *levelOrder(TreeNode *root, int *size) {
    int front, rear;
    int index, *arr;
    TreeNode *node;
    TreeNode **queue;

    queue = malloc(sizeof(TreeNode *) * MAX_SIZE);
    front = 0, rear = 0;
    queue[rear++] = root;
    arr = malloc(sizeof(int) * MAX_SIZE);
    index = 0;
    while (front < rear) {
        node = queue[front++];
        arr[index++] = node->val;
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
    *size = index;
    arr = realloc(arr, sizeof(int) * (*size));
    free(queue);
    return arr;
}
