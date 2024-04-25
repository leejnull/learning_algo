#include <stdlib.h>

/**
 * 给定 n 个物品，第 i 个物品的重量为 wgt[i-1]、价值为 val[i-1]，和一个容量为 cap 的背包。
 * 每个物品只能选择一次，问在限定背包容量下能放入物品的最大价值。
*/

int max(int a, int b) {
    return a > b ? a : b;
}

/* 0-1 背包：暴力搜索 */
int knapspackDFS(int wgt[], int val[], int i, int c) {
    // 若已选完所有物品或背包无剩余容量，则返回价值0
    if (i == 0 || c == 0) {
        return 0;
    }
    // 若超过背包容量，则只能选择跳过
    if (wgt[i - 1] > c) {
        return knapspackDFS(wgt, val, i - 1, c);
    }
    // 计算不放入和放入物品 i 的最大价值
    int no = knapspackDFS(wgt, val, i - 1, c);
    int yes = knapspackDFS(wgt, val, i - 1, c - wgt[i - 1] + val[i - 1]);
    return max(no, yes);
}

/* 0-1 背包：记忆化搜索 */
int knapsackDFSMem(int wgt[], int val[], int memCols, int **mem, int i, int c) {
    if (i == 0 || c == 0) {
        return 0;
    }
    if (mem[i][c] != -1) {
        return mem[i][c];
    }
    if (wgt[i - 1] > c) {
        return knapsackDFSMem(wgt, val, memCols, mem, i - 1, c);
    }
    int no = knapsackDFSMem(wgt, val, memCols, mem, i - 1, c);
    int yes = knapsackDFSMem(wgt, val, memCols, mem, i - 1, c - wgt[i - 1] + val[i - 1]);
    mem[i][c] = max(no, yes);
    return mem[i][c];
}

/* 0-1 背包：动态规划 */
int knapsackDP(int wgt[], int val[], int cap, int wgtSize) {
    int n = wgtSize;
    // 初始化dp表
    int **dp = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = malloc(sizeof(int) * (cap + 1));
    }
    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                dp[i][c] = dp[i - 1][c];
            } else {
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[n][cap];
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    return res;
}

/* 0-1 背包：空间优化后的动态规划 */
int knapsackDPComp(int wgt[], int val[], int cap, int wgtSize) {
    int n = wgtSize;
    int *dp = malloc(sizeof(int) * (cap + 1));
    for (int i = 1; i <= n; i++) {
        for (int c = cap; c >= 1; c--) {
            if (wgt[i - 1] <= c) {
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[cap];
    free(dp);
    return res;
}
