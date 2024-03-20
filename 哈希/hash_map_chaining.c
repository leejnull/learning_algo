#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char *val;
} Pair;

typedef struct node {
    Pair *pair;
    struct node *next;
} Node;

typedef struct {
    int size;
    int capacity;
    double loadThres;
    int extendRatio;
    Node* *buckets;
} HashMapChaining;

void extendMap(HashMapChaining *);
char *getItem(HashMapChaining *, int);
void putItem(HashMapChaining *, int, const char *);

HashMapChaining *newHashMapChining() {
    HashMapChaining *hmap = malloc(sizeof(HashMapChaining));
    hmap->size = 0;
    hmap->capacity = 4;
    hmap->loadThres = 2.0 / 3.0;
    hmap->extendRatio = 2;
    hmap->buckets = malloc(sizeof(Node *) * hmap->capacity);
    for (int i = 0; i < hmap->capacity; i++) {
        hmap->buckets[i] = NULL;
    }
    return hmap;
}

void delHashMaoChaining(HashMapChaining *hmap) {
    for (int i = 0; i < hmap->capacity; i++) {
        Node *cur = hmap->buckets[i];
        while (cur) {
            Node *temp = cur;
            cur = cur->next;
            free(temp->pair->val);
            free(temp->pair);
            free(temp);
        }
    }
    free(hmap->buckets);
    free(hmap);
}

int hashFunc(HashMapChaining *hmap, int key) {
    return key % hmap->capacity;
}

double loadFactor(HashMapChaining *hmap) {
    return (double)hmap->size / (double)hmap->capacity;
}

char *getItem(HashMapChaining *hmap, int key) {
    int index = hashFunc(hmap, key);
    Node *cur = hmap->buckets[index];
    while (cur) {
        if (cur->pair->key == key) {
            return cur->pair->val;
        }
        cur = cur->next;
    }
    return NULL;
}

void putItem(HashMapChaining *hmap, int key, const char *val) {
    if (loadFactor(hmap) > hmap->loadThres) {
        extendMap(hmap);
    }
    int index = hashFunc(hmap, key);
    Node *cur = hmap->buckets[index];
    while (cur) {
        if (cur->pair->key == key) {
            strcpy(cur->pair->val, val);
            return;
        }
        cur = cur->next;
    }
    Pair *pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->val = malloc(strlen(val) + 1);
    strcpy(pair->val, val);
    Node *node = malloc(sizeof(Node));
    node->pair = pair;
    node->next = hmap->buckets[index];
    hmap->buckets[index] = node;
    hmap->size += 1;
}

void extendMap(HashMapChaining *hmap) {
    int oldCapacity = hmap->capacity;
    Node* *oldBuckets = hmap->buckets;
    hmap->capacity *= hmap->extendRatio;
    hmap->buckets = malloc(sizeof(Node *) * hmap->capacity);
    for (int i = 0; i < hmap->capacity; i++) {
        hmap->buckets[i] = NULL;
    }
    hmap->size = 0;
    for (int i = 0; i < oldCapacity; i++) {
        Node *cur = oldBuckets[i];
        while (cur) {
            putItem(hmap, cur->pair->key, cur->pair->val);
            Node *temp = cur;
            cur = cur->next;
            free(temp->pair->val);
            free(temp->pair);
            free(temp);
        }
    }
    free(oldBuckets);
}

void removeItem(HashMapChaining *hmap, int key) {
    int index = hashFunc(hmap, key);
    Node *cur = hmap->buckets[index];
    Node *pre = NULL;
    while (cur) {
        if (cur->pair->key == key) {
            if (pre) {
                pre->next = cur->next;
            } else {
                hmap->buckets[index] = cur->next;
            }
            free(cur->pair->val);
            free(cur->pair);
            free(cur);
            hmap->size -= 1;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}

void print(HashMapChaining *hmap) {
    for (int i = 0; i < hmap->capacity; i++) {
        Node *cur = hmap->buckets[i];
        if (cur) {
            printf("[");
            while (cur) {
                printf("%d -> %s, ", cur->pair->key, cur->pair->val);
                cur = cur->next;
            }
            printf("]\n");
        }
    }
}

int main() {
    HashMapChaining *hmap = newHashMapChining();
    putItem(hmap, 101, "AAA");
    putItem(hmap, 102, "BBB");
    putItem(hmap, 103, "CCC");
    putItem(hmap, 1001, "AAAAAA");
    print(hmap);
    return 1;
}
