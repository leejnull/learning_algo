#include <stdlib.h>

void siftDown(int nums[], int n, int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int ma = i;
        if (l < n && nums[l] > nums[ma]) {
            ma = l;
        }
        if (r < n && nums[r] > nums[ma]) {
            ma = r;
        }
        if (ma == i) {
            break;
        }
        int tmp = nums[i];
        nums[i] = nums[ma];
        nums[ma] = tmp;
        i = ma;
    }
}

void heapSort(int nums[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(nums, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        int tmp = nums[0];
        nums[0] = nums[i];
        nums[i] = tmp;
        siftDown(nums, i, 0);
    }
}
