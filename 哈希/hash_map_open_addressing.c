#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int key;
    char *val;
} Pair;

/* 开放寻址哈希表 */
typedef struct {
    int size;         // 键值对数量
    int capacity;     // 哈希表容量
    double loadThres; // 触发扩容的负载因子阈值
    int extendRatio;  // 扩容倍数
    Pair **buckets;   // 桶数组
    Pair *TOMBSTONE;  // 删除标记
} HashMapOpenAddressing;

/* 构造函数 */
HashMapOpenAddressing *newHashMapOpenAddressing() {
    HashMapOpenAddressing *hashMap = (HashMapOpenAddressing *)malloc(sizeof(HashMapOpenAddressing));
    hashMap->size = 0;
    hashMap->capacity = 4;
    hashMap->loadThres = 2.0 / 3.0;
    hashMap->extendRatio = 2;
    hashMap->buckets = (Pair **)malloc(sizeof(Pair *) * hashMap->capacity);
    hashMap->TOMBSTONE = (Pair *)malloc(sizeof(Pair));
    hashMap->TOMBSTONE->key = -1;
    hashMap->TOMBSTONE->val = "-1";

    return hashMap;
}

/* 析构函数 */
void delHashMapOpenAddressing(HashMapOpenAddressing *hashMap) {
    for (int i = 0; i < hashMap->capacity; i++) {
        Pair *pair = hashMap->buckets[i];
        if (pair != NULL && pair != hashMap->TOMBSTONE) {
            free(pair->val);
            free(pair);
        }
    }
}

/* 哈希函数 */
int hashFunc(HashMapOpenAddressing *hashMap, int key) {
    return key % hashMap->capacity;
}

/* 负载因子 */
double loadFactor(HashMapOpenAddressing *hashMap) {
    return (double)hashMap->size / (double)hashMap->capacity;
}

/* 搜索 key 对应的桶索引 */
int findBucket(HashMapOpenAddressing *hashMap, int key) {
    int index = hashFunc(hashMap, key);
    int firstTombstone = -1;
    while (hashMap->buckets[index] != NULL) {
        if (hashMap->buckets[index]->key == key) {
            if (firstTombstone != -1) {
                hashMap->buckets[firstTombstone] = hashMap->buckets[index];
                hashMap->buckets[index] = hashMap->TOMBSTONE;
                return firstTombstone;
            }
            return index;
        }
        if (firstTombstone == -1 && hashMap->buckets[index] == hashMap->TOMBSTONE) {
            firstTombstone = index;
        }
        index = (index + 1) % hashMap->capacity;
    }
    return firstTombstone != -1 ? firstTombstone : index;
}

/* 查询操作 */
char *get(HashMapOpenAddressing *hashMap, int key) {
    int index = findBucket(hashMap, key);
    if (hashMap->buckets[index] != NULL && hashMap->buckets[index] != hashMap->TOMBSTONE) {
        return hashMap->buckets[index]->val;
    }
    return "";
}

/* 添加操作 */
void put(HashMapOpenAddressing *hashMap, int key, char *val) {
    if (loadFactor(hashMap) > hashMap->loadThres) {
        extend(hashMap);
    }
    int index = findBucket(hashMap, key);
    // 存在则覆盖
    if (hashMap->buckets[index] != NULL && hashMap->buckets[index] != hashMap->TOMBSTONE) {
        Pair *pair = hashMap->buckets[index];
        free(pair->val);
        pair->val = malloc(sizeof(char) * (strlen(val) + 1));
        strcpy(pair->val, val);
        pair->val[strlen(val)] = "\0";
        return;
    }
    // 不存在添加
    Pair *pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->val = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(pair->val, val);
    pair->val[strlen(val)] = "\0";
    hashMap->buckets[index] = pair;
    hashMap->size += 1;
}

/* 删除操作 */
void removeItem(HashMapOpenAddressing *hashMap, int key) {
    int index = hashFunc(hashMap, key);
    if (hashMap->buckets[index] != NULL && hashMap->buckets[index] != hashMap->TOMBSTONE) {
        Pair *pair = hashMap->buckets[index];
        free(pair->val);
        free(pair);
        hashMap->buckets[index] = hashMap->TOMBSTONE;
        hashMap->size -= 1;
    }
}

/* 扩容哈希表 */
void extend(HashMapOpenAddressing *hashMap) {
    Pair **oldBuckets = hashMap->buckets;
    int oldCapacity = hashMap->capacity;
    hashMap->capacity *= hashMap->extendRatio;
    hashMap->buckets = malloc(sizeof(Pair) * hashMap->capacity);
    hashMap->size = 0;
    for (int i = 0; i < oldCapacity; i++) {
        Pair *pair = oldBuckets[i];
        if (pair != NULL && pair != hashMap->TOMBSTONE) {
            put(hashMap, pair->key, pair->val);
            free(pair->val);
            free(pair);
        }
    }
    free(oldBuckets);
}

/* 打印哈希表 */
void print(HashMapOpenAddressing *hashMap) {
    for (int i = 0; i < hashMap->capacity; i++) {
        Pair *pair = hashMap->buckets[i];
        if (pair == NULL) {
            printf("NULL\n");
        } else if (pair == hashMap->TOMBSTONE) {
            printf("TOMBSTONE\n");
        } else {
            printf("%d -> %s\n", pair->key, pair->val);
        }
    }
}