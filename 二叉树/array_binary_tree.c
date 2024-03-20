#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int *tree;
    int size;
} ArrayBinaryTree;

ArrayBinaryTree *newArrayBinaryTree(int *arr, int size) {
    ArrayBinaryTree *abt = malloc(sizeof(ArrayBinaryTree));
    abt->tree = malloc(sizeof(int) * size);
    memcpy(abt->tree, arr, sizeof(int) * size);
    abt->size = size;
    return abt;
}

void delArrayBinaryTree(ArrayBinaryTree *abt) {
    free(abt->tree);
    free(abt);
}

int size(ArrayBinaryTree *abt) {
    return abt->size;
}

int val(ArrayBinaryTree *abt, int i) {
    if (i < 0 || i >= size(abt)) {
        return INTMAX_MAX;
    }
    return abt->tree[i];
}

int *level(ArrayBinaryTree *abt, int *returnSize) {
    int *res = malloc(sizeof(int) * size(abt));
    int index = 0;
    for (int i = 0; i < size(abt); i++) {
        if (val(abt, i) < INTMAX_MAX) {
            res[index++] = val(abt, i);
        }
    }
    *returnSize = index;
    return res;
}

int left(int i) {
    return 2 * i - 1;
}

int right(int i) {
    return 2 * i + 1;
}

void dfs(ArrayBinaryTree *abt, int i, char *order, int *res, int* index) {
    if (val(abt, i) == INTMAX_MAX) {
        return;
    }
    if (strcmp(order, "pre") == 0) {
        res[(*index)++] = val(abt, i);
    }
    dfs(abt, left(i), order, res, index);
    if (strcmp(order, "in") == 0) {
        res[(*index)++] = val(abt, i);
    }
    dfs(abt, right(i), order, res, index);
    if (strcmp(order, "post") == 0) {
        res[(*index)++] = val(abt, i);
    }
}

int *preOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = malloc(sizeof(int) * size(abt));
    int index = 0;
    dfs(abt, 0, "pre", res, &index);
    *returnSize = index;
    return res;
}

int *inOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = malloc(sizeof(int) * size(abt));
    int index = 0;
    dfs(abt, 0, "in", res, &index);
    *returnSize = index;
    return res;
}

int *postOrder(ArrayBinaryTree *abt, int *returnSize) {
    int *res = malloc(sizeof(int) * size(abt));
    int index = 0;
    dfs(abt, 0, "post", res, &index);
    *returnSize = index;
    return res;
}
