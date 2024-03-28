#include <stdio.h>

void bubbleSort(int nums[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
}

int main() {
    int nums[6] = {4, 1, 3, 1, 5, 2};
    bubbleSort(nums, 6);
    return 1;
}