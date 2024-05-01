#include <stdlib.h>

/**
 * 给定 n 个物品，第 i 个物品的重量为 wgt[i - 1]、价值为 val[i - 1]，和一个容量为 cap 的背包。
 * 每个物品只能选择一次，但可以选择物品的一部分，价值根据选择的重量比例计算，问在限定背包容量下背包中物品的最大价值
*/

typedef struct {
    int w;
    int v;
} Item;

int sortByValueDensity(Item *a, Item *b) {
    float v1 = a->v / a->w;
    float v2 = a->v / a->w;
    if (v1 > v2) {
        return 1;
    }
    if (v1 < v2) {
        return -1;
    }
    return 0;
}

/* 分数背包：贪心 */
float fractionalKnapsack(int wgt[], int val[], int itemCount, int cap) {
    Item *items = malloc(sizeof(Item) * itemCount);
    for (int i = 0; i < itemCount; i++) {
        items[i] = (Item){.w = wgt[i], .v = val[i]};
    }
    qsort(items, (size_t)itemCount, sizeof(Item), sortByValueDensity);
    float res = 0.0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i].w <= cap) {
            res += items[i].v;
            cap -= items[i].w;
        } else {
            res += (float)cap * items[i].v / items[i].w;
            cap = 0;
            break;
        }
    }
    free(items);
    return res;
}
