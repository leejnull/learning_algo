#include <stdlib.h>
#include <string.h>

/**
 * 输入两个字符串 s 和 t，返回将 s 转换为 t 所需的最少编辑步数。
 * 你可以在一个字符串中进行三种编辑操作：插入一个字符、删除一个字符、将字符替换为任意一个字符。
*/

int min(int a, int b, int c) {
    int tmp = a < b ? a : b;
    return tmp < c ? tmp : c;
}

/* 编辑距离：动态规划 */
int editDistanceDP(char *s, char *t, int n, int m) {
    int **dp = malloc(sizeof((int *)) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i] = malloc(sizeof(int) * (m + 1));
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    int res = dp[n][m];
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/* 编辑距离：空间优化后的动态规划 */
int editDistanceDPComp(char *s, char *t, int n, int m) {
    // dp数组表示一行的状态
    int *dp = malloc(sizeof(int) * (m + 1));
    // 初始化第 0 行，假设 s 是空的，则每一位 t 都需要对应 j 次
    for (int j = 1; j <= m; j++) {
        dp[j] = j;
    }
    // 从第 1 行开始
    for (int i = 1; i <= n; i++) {
        // 记录第 0 行左上角数据
        int leftup = dp[0];
        // 更新第 1 行第 0 位数据
        dp[0] = i;
        for (int j = 1; j <= m; j++) {
            // 每一个 dp[j] 的数据，都依赖于左，上，左上，前两个都可以直接得到，左上
            // 需要记录，不然接下来就会被覆盖
            int temp = dp[j];
            // 如果两个字符相等，则状态不用转移
            if (s[i - 1] == t[j - 1]) {
                // 相当于 dp[i][j] = dp[i-1][j-1]
                dp[j] = leftup;
            } else {
                dp[j] = min(dp[j - 1], dp[j], leftup) + 1;
            }
            leftup = temp;
        }
    }
    int res = dp[m];
    free(dp);
    return res;
}
