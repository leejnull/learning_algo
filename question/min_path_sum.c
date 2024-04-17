#include <limits.h>
#include <stdlib.h>

/**
 * 给定一个 n x m 的二维网格 grid ，网格中的每个单元格包含一个非负整数，表示该单元格的代价。
 * 机器人以左上角单元格为起始点，每次只能向下或者向右移动一步，直至到达右下角单元格。请返回从左上角到右下角的最小路径和。
*/

#define MAX_SIZE 128

int min(int a, int b) {
    return a < b ? a : b;
}

/*最小路径和：暴力搜索*/
int minPathSumDFS(int grid[MAX_SIZE][MAX_SIZE], int i, int j) {
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    // 若行列索引越界，则返回 +∞ 代价
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);
    return min(up, left) != INT_MAX ? min(up, left) + grid[i][j] : INT_MAX;
}

/*最小路径和：记忆化搜索*/
int minPathSumDFSMem(int grid[MAX_SIZE][MAX_SIZE], int mem[MAX_SIZE][MAX_SIZE], int i, int j) {
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    // 若行列索引越界，则返回 +∞ 代价
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    // 若已有记录，则直接返回
    if (mem[i][j] != -1) {
        return mem[i][j];
    }
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);
    mem[i][j] = min(up, left) != INT_MAX ? min(up, left) + grid[i][j] : INT_MAX;
    return mem[i][j];
}

/*最小路径和：动态规划*/
int minPathSumDP(int grid[MAX_SIZE][MAX_SIZE], int n, int m) {
    // 初始化 dp 表
    int **dp = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = malloc(sizeof(int) * m);
    }
    dp[0][0] = grid[0][0];
    // 状态转移：首行
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    // 状态转移：首列
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // 状态转移：其余行和列
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    int res = dp[n - 1][m - 1];
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/*最小路径和：空间优化后的动态规划*/
int minPathSumDPComp(int grid[MAX_SIZE][MAX_SIZE], int n, int m) {
    int *dp = malloc(sizeof(int) * m);
    dp[0] = grid[0][0];
    for (int j = 1; j < m; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; i++) {
        dp[0] = dp[0] + grid[i][0];
        for (int j = 1; j < m; j++) {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    int res = dp[m - 1];
    free(dp);
    return res;
}
