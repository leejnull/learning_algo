#include <stdlib.h>
#include <stdio.h>

void merge(int *nums, int left, int mid, int right) {
    int tmpSize = right - left + 1;
    int *tmp = malloc(sizeof(int) * tmpSize);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= right) {
        tmp[k++] = nums[j++];
    }
    for (k = 0; k < tmpSize; k++) {
        nums[left + k] = tmp[k];
    }
    free(tmp);
}

void mergeSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid+1, right);
    merge(nums, left, mid, right);
}

int main() {
    int *nums = malloc(sizeof(int)*4);
    int arr[4] = {7, 3, 2, 6};
    for (int i = 0; i < 4; i++) {
        nums[i] = arr[i];
    }
    mergeSort(nums, 0, 3);
    for (int i = 0; i < 4; i++) {
        printf("%d ", nums[i]);
    }
    return 1;
}
