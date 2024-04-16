#include <stdlib.h>

/**
 * 给定一个共有 n 阶的楼梯，你每步可以上 1 阶或者 2 阶，但不能连续两轮跳 1 阶，请问有多少种方案可以爬到楼顶？
 * 
 * 如果上一轮跳了 1 阶，这一轮只能跳 2 阶
 * 如果上一轮跳了 2 阶，这一轮能跳 1 阶 或者 2 阶
 * 
 * 状态转移方程
 * 
 * dp[i, 1] = dp[i - 1, 2]
 * dp[i, 2] = dp[i - 2, 1] + dp[i - 2, 2]
*/

int climbingStairsConstraintDP(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    // 初始化 dp 表，用于存储子问题的解
    int **dp = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = calloc(3, sizeof(int));
    }
    // 初始状态，预设最小子问题的解
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; i++) {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    int res = dp[n][1] + dp[n][2];
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}
