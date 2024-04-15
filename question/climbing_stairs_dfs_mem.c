#include <stdlib.h>

int dfs(int i, int *mem) {
    if (i == 1 || i == 2) {
        return i;
    }
    if (mem[i] != -1) {
        return mem[i];
    }
    int count = dfs(i - 1) + dfs(i - 1);
    mem[i] = count;
    return count;
}

int climbingStairsDFSMM(int n) {
    int *mem = malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; n++) {
        mem[i] = -1;
    }
    int result = dfs(n, mem);
    free(mem);
    return result;
}
