#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b) {
    float *tmp = a;
    a = b;
    b = a;
}

void bucketSort(float nums[], int size) {
    int k = size / 2;
    float **buckets = calloc(k, sizeof(float *));
    for (int i = 0; i < k; i++) {
        buckets[i] = calloc(size, sizeof(float));
    }
    for (int i = 0; i < size; i++) {
        int bucket_idx = nums[i] * k;
        int j = 0;
        while (buckets[bucket_idx][j] > 0 && buckets[bucket_idx][j] < nums[i]) {
            j++;
        }
        float temp = nums[i];
        while (j < size && buckets[bucket_idx][j] > 0) {
            swap(&temp, &buckets[bucket_idx][j]);
            j++;
        }
        buckets[bucket_idx][j] = temp;
    }

    // 2. 对各个桶执行排序
    for (int i = 0; i < k; i++) {

    }

    // 3. 遍历桶合并结果
    for (int i = 0, j = 0; j < k; j++) {
        for (int l = 0; l < size; l++) {
            if (buckets[j][l] > 0) {
                nums[i++] = buckets[j][l];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        free(buckets[i]);
    }
    free(buckets);
}