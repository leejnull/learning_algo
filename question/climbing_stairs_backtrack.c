#include <stdlib.h>

void backtrack(int *choices, int state, int n, int *res, int len) {
    if (state == n) {
        *res++;
        return;
    }
    for (int i = 0; i < len; i++) {
        state += choices[i];
        if (state > n) {
            continue;
        }
        backtrack(choices, state, n, res, len);
        state -= choices[i];
    }
}

int climbingStairsBacktrack(int n) {
    int choices[2] = {1, 2};
    int state = 0;
    int *res = malloc(sizeof(int));
    *res = 0;
    int len = sizeof(choices) / sizeof(int);
    backtrack(choices, state, n, res, leng);
    int result = *res;
    free(res);
    return result;
}