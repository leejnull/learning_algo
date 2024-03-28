void swap(int nums[], int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int medianThree(int nums[], int left, int mid, int right) {
    int l = nums[left], m = nums[mid], r = nums[right];
    if ((l <= m && m <= r) || (l >= m && m >= r)) {
        return mid;
    }
    if ((m <= l && l <= r) || (r <= l && l <= m)) {
        return left;
    }
    return right;
}

int partitionMedian(int nums[], int left, int right) {
    int med = medianThree(nums, left, (left + right)/2, right);
    swap(nums, left, med);
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            i++;
        }
        swap(nums, i, j);
    }
    swap(nums, i, left);
    return i;
}

int partition(int nums[], int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            i++;
        }
        swap(nums, i, j);
    }
    swap(nums, i, left);
    return i;
}

void quickSort(int nums[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}
