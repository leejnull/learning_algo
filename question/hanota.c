void move(int *src, int *srcSize, int *tar, int *tarSize) {
    int pan = src[*srcSize - 1];
    src[*srcSize - 1] = 0;
    (*srcSize)--;
    tar[*tarSize] = pan;
    (*tarSize)++;
}

void dfs(int i, int *src, int *srcSize, int *buf, int *bufSize, int *tar, int *tarSize) {
    if (i == 1) {
        move(src, srcSize, tar, tarSize);
        return;
    }
    dfs(i - 1, src, srcSize, tar, tarSize, buf, bufSize);
    move(src, srcSize, tar, tarSize);
    dfs(i - 1, buf, bufSize, src, srcSize, tar, tarSize);
}

void solveHanota(int *A, int *ASize, int *B, int *BSize, int *C, int *CSize) {
    dfs(*ASize, A, ASize, B, BSize, C, CSize);
}