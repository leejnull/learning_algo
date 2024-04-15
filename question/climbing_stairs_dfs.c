/**
 * 指数级增长
*/
int dfs(int i) {
    if (i == 1 || i == 2) {
        return i;
    }
    int count = dfs(i-1) + dfs(i-2);
    return count;
}

int climbingStairsDFS(int n) {
    return dfs(n);
}
