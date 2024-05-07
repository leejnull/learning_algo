#include <stdio.h>

/**
 * 输入一个数组 ht，其中的每个元素代表一个垂直隔板的高度。数组中的任意两个隔板，以及它们之间的空间可以组成一个容器。
 * 容器的容量等于高度和宽度的乘积（面积），其中高度由较短的隔板决定，宽度是两个隔板的数组索引之差。
 * 请在数组中选择两个隔板，使得组成的容器的容量最大，返回最大容量。
*/

int max(int a, int b) {
    return a < b ? b : a;
}

/* 最大容量：贪心 */
int maxCapacity(int ht[], int htLength) {
    // 初始化首位指针
    int i = 0;
    int j = htLength - 1;
    int res = 0;
    while (i < j) {
        int w = j - i;
        int h = 0;
        if (ht[i] < ht[j]) {
            h = ht[i];
            i += 1;
        } else {
            h = ht[j];
            j -= 1;
        }
        res = max(res, w * h);
    }
    return res;
}