#include "binary_search_insertion.h"

int binarySearchLeftEdge(int *nums, int numSize, int target) {
    int i = binarySearchInsertion(nums, numSize, target);
    if (i == numSize || nums[i] != target) {
        return -1;
    }
    return i;
}