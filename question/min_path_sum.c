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
