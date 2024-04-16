#include <stdlib.h>

/**
 * 给定一个楼梯，你每步可以上 1 阶或者 2 阶，每一阶楼梯上都贴有一个非负整数，表示你在该台阶所需要付出的代价。给定一个非负整数数组 cost ，
 * 其中 cost[i] 表示在第 i 个台阶需要付出的代价，cost[0] 为地面（起始点）。请计算最少需要付出多少代价才能到达顶部？
*/

int min(int a, int b) {
    return a < b ? a : b;
}

/* 爬楼梯最小代价：动态规划 */
int minCostClimbingStairsDP(int cost[], int costSize) {
    int n = costSize - 1;
    if (n == 1 || n == 2) {
        return cost[n];
    }
    // 初始化 dp 表，用于存储子问题的解
    int *dp = malloc(sizeof(int) * (n + 1));
    dp[1] = cost[1];
    dp[2] = cost[2];
    for (int i = 3; i < n; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    int res = dp[n];
    free(dp);
    return res;
}

/* 爬楼梯最小代价：空间优化后的动态规划 */
int minCostClimbingStairsDPComp(int cost[], int costSize) {
    int n = costSize - 1;
    if (n == 1 || n == 2) {
        return cost[n];
    }
    int dp1 = cost[1];
    int dp2 = cost[2];
    for (int i = 3; i <= n; i++) {
        int tmp = dp2;
        dp2 = min(dp1, dp2) + cost[i];
        dp1 = tmp;
    }
    return dp2;
}
