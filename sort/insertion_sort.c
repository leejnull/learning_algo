void insertionSort(int nums[], int size) {
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}