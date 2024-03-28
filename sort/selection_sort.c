#include <stdio.h>

void selectionSort(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);    
    }
}

int main() {
    int nums[6] = {4, 4, 3, 1, 5, 2};
    selectionSort(nums, 6);
    return 1;
}