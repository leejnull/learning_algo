#include <stdlib.h>

/**
 * 动态规划
 * 
 * 1. 将数组 dp 成为 dp表，dp[i] 表示状态 i 对应子问题的解。
 * 2. 将最小子问题对应的状态（第 1 阶和第 2 阶楼梯）称为初始状态。
 * 3. 将递推公式 dp[i] = dp[i - 1] + dp[i - 2] 称为状态转移方程。
 * */
int climbingStairsDP(int n) {
    if (n == 1 || n == 2) {
        return n;
    }
    // 初始化 dp 表，用于存储子问题的解
    int *dp = malloc(sizeof(int) * (n+1));
    // 初始状态：预设最小子问题的解
    dp[1] = 1;
    dp[2] = 2;
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int result = dp[n];
    free(dp);
    return result;
}

int climbingStairsDPComp(int n) {
    if (n == 1 || n == 2) {
        return n;
    }
    int dp1 = 1;
    int dp2 = 2;
    for (int i = 3; i <= n; i++) {
        int tmp = dp2;
        dp2 = dp1 + dp2;
        dp1 = tmp;
    }
    return dp2;
}