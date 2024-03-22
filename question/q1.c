#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    int y;
    struct Node *right;
    struct Node *bottom;
} Node;

Node *newMatrixNode(int row, int column) {
    Node **nodes = malloc(sizeof(Node*) * row * column);
    int size = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            Node *node = malloc(sizeof(Node));
            node->x = i;
            node->y = j;
            nodes[size++] = node;
        }
    }
    Node *root = nodes[0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            int index = i * column + j;
            Node *node = nodes[index];
            int rightIndex = i * column + j + 1;
            if (rightIndex < size && j < column - 1) {
                node->right = nodes[rightIndex];
            }
            int bottomIndex = (i + 1) * column + j;
            if (bottomIndex < size && i < row - 1) {
                node->bottom = nodes[bottomIndex];
            }
        }
    }
    return root;
}

int findPaths(Node *node, int x, int y) {
    if (node == NULL) {
        return 0;
    }
    if (node->x == x && node->y == y) {
        return 1;
    }
    int rightCount = 0;
    if (node->right != NULL) {
        rightCount = findPaths(node->right, x, y);
    }
    int bottomCount = 0;
    if (node->bottom != NULL) {
        bottomCount = findPaths(node->bottom, x, y);
    }
    return rightCount + bottomCount;
}

int main() {
    Node *root = newMatrixNode(3, 7);
    int res = findPaths(root, 2, 6);
    printf("路径数量：%d\n", res);
    free(root);
    return 1;
}

