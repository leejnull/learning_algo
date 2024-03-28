#include "binary_search_insertion.h"

int binarySearchInsertionSimple(int *nums, int numSize, int target) {
    int i = 0, j = numSize - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            return m;
        }
    }
    return i;
}

int binarySearchInsertion(int *nums, int numSize, int target) {
    int i = 0, j = numSize - 1;
    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        } else if (nums[m] > target) {
            j = m - 1;
        } else {
            j = m - 1;
        }
    }
    return i;
}