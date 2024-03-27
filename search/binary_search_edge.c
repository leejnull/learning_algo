#include "binary_search_insertion.h"

int binarySearchLeftEdge(int *nums, int numSize, int target) {
    int i = binarySearchInsertion(nums, numSize, target);
    if (i == numSize || nums[i] != target) {
        return -1;
    }
    return i;
}

/*
查找右边界等价于查找target+1的左边界
*/
int binarySearchRightEdge(int *nums, int numSize, int target) {
    int i = binarySearchInsertion(nums, numSize, target + 1);
    int j = i - 1;
    if (j == -1 || nums[j] != target) {
        return -1;
    }
    return j;
}
