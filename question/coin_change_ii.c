#include <stdlib.h>

/**
 * 给定 n 种硬币，第 i 种硬币的面值为 coins[i-1]，目标金额为 amt，
 * 每种硬币可以重复选取，问凑出目标金额的硬币组合数量。
*/

/* 零钱兑换 II：动态规划 */
int coinChangeIIDP(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    int **dp = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = malloc(sizeof(int) * (amt + 1));
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    } 
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                dp[i][a] = dp[i - 1][a];
            } else {
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
        }
    }
    int res = dp[n][amt];
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/* 零钱兑换 II：空间优化后的动态规划 */
int coinChangeIIDPComp(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    int *dp = malloc(sizeof(int) * (amt + 1));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                dp[a] = dp[a];
            } else {
                dp[a] = dp[a - coins[i - 1]] + dp[a];
            }
        }
    }
    int res = dp[amt];
    free(dp);
    return res;
}
