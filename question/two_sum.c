#include "uthash.h"
#include <stdio.h>

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashTable;

HashTable *find(HashTable *h, int key) {
    HashTable *tmp;
    HASH_FIND_INT(h, &key, tmp);
    return tmp;
}

void insert(HashTable *h, int key, int val) {
    HashTable *t = find(h, key);
    if (t == NULL) {
        HashTable *tmp = malloc(sizeof(HashTable));
        tmp->key = key, tmp->val = val;
        HASH_ADD_INT(h, key, tmp);
    } else {
        t->val = val;
    }
}

int *twoSumHashTable(int *nums, int numSize, int target, int *returnSize) {
    HashTable *hashTable = NULL;
    for (int i = 0; i < numSize; i++) {
        HashTable *t = find(hashTable, target - nums[i]);
        printf("t = %p\n", t);
        if (t) {
            int *res = malloc(sizeof(int)*2);
            res[0] = t->val, res[1] = i;
            *returnSize = 2;
            return res;
        }
        insert(hashTable, nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int *returnSize = malloc(sizeof(int));
    int *nums = malloc(sizeof(int) * 4);
    nums[0] = 2, nums[1] = 7, nums[2] = 11, nums[3] = 15;
    int *res = twoSumHashTable(nums, 4, 13, returnSize);
    printf("returnSize: %d\n", *returnSize);
    if (*returnSize > 0) {
        for (int i = 0; i < *returnSize; i++) {
            printf("%d ", res[i]);
        }
    }
    return 1;
}
