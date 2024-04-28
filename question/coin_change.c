#include <stdlib.h>

/**
 * 给定 n 种硬币，第 i 种硬币的面值为 coins[i - 1]，目标金额为 amt，
 * 每种硬币可以重复选取，问能够凑出目标金额的最少硬币数量。如果无法凑出目标金额，则返回 -1。
*/

int min(int a, int b) {
    return a < b ?  a : b;
}

/* 零钱兑换：动态规划 */
int coinChangeDP(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    int MAX = amt + 1;
    int **dp = malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = malloc(sizeof(int) * (amt + 1));
    }
    for (int a = 1; i <= amt; i++) {
        dp[0][a] = MAX;
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                dp[i][a] = dp[i - 1][a];
            } else {
                dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    int res = dp[n][amt] == MAX ? -1 : dp[n][amt];
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/* 零钱兑换：空间优化后的动态规划 */
int coinChangeDPComp(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    int MAX = amt + 1;
    int *dp = malloc(sizeof(int) * (amt + 1));
    for (int a = 1; a <= amt; a++) {
        dp[a] = MAX;
    }
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                dp[a] = dp[a];
            } else {
                dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
            }
        }
    }
    int res = dp[amt] == MAX ? -1 : dp[amt];
    free(dp);
    return res;
}