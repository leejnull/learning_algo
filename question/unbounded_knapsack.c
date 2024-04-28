#include <stdlib.h>

/**
 * 完全背包问题
 * 
 * 给定 n 个物品，第 i 个物品的重量为 wgt[i-1]、价值为 val[i-1]，和一个容量为 cap
 的背包。每个物品可以重复选取，问在限定背包容量下能放入物品的最大价值
*/

int max(int a, int b) {
    return a > b ?  a : b;
}

/* 完全背包：动态规划 */
int unboundedKnapsackDP(int wgt[], int val[], int cap, int wgtSize) {
    int n = wgtSize;
    int **dp = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = malloc(sizeof(int) * (cap + 1));
    }
    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] < c) {
                dp[i][c] = dp[i-1][c];
            } else {
                dp[i][c] = max(dp[i-1][c], dp[i][c - wgt[i-1]] + val[i-1]);
            }
        }
    }
    int res = dp[n][cap];
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/* 完全背包：空间优化后的动态规划 */
int unboundedKnapsackDPComp(int wgt[], int val[], int cap, int wgtSize) {
    int n = wgtSize;
    int *dp = malloc(sizeof(int) * (cap + 1));
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                dp[c] = dp[c]
            } else {
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[cap];
    free(dp);
    return res;
}
