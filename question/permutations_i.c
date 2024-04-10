#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * 输入一个整数数组，其中不包含重复元素，返回所有可能的排列。
*/
void backtrack(int *state, int stateSize, int *choices, int choiceSize, bool *selected, int **res, int *resSize) {
    if (stateSize == choiceSize) {
        res[*resSize] = malloc(sizeof(int) * choiceSize);
        for (int i = 0; i < choiceSize; i++) {
            res[*resSize][i] = state[i];
        }
        (*resSize)++;
        return;
    }
    for (int i = 0; i < choiceSize; i++) {
        int choice = choices[i];
        if (!selected[i]) {
            selected[i] = true;
            state[stateSize] = choice;
            backtrack(state, stateSize+1, choices, choiceSize, selected, res, resSize);
            selected[i] = false;
        }
    }
}

int **permutationI(int *nums, int numSize, int *returnSize) {
    int *state = malloc(sizeof(int) * numSize);
    bool *selected = malloc(sizeof(bool) * numSize);
    for (int i = 0; i < numSize; i++) {
        selected[i] = false;
    }
    int **res = malloc(sizeof(int *) * numSize ^ 2);
    *returnSize = 0;

    backtrack(state, 0, nums, numSize, selected, res, returnSize);

    free(state);
    free(selected);

    return res;
}

int main() {
    int nums[3] = {1, 2, 3};
    int *returnSize = malloc(sizeof(int));

    int **res = permutationI(nums, 3, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
