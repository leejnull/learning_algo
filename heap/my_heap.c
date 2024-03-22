#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 64

typedef struct MaxHeap {
    int *data;
    int size;
} MaxHeap;

MaxHeap *newMaxHeap() {
    MaxHeap *maxHeap = malloc(sizeof(MaxHeap));
    maxHeap->data = malloc(sizeof(int) * MAX_CAPACITY);
    maxHeap->size = 0;
    return maxHeap;
}

int left(MaxHeap *maxHeap, int i) {
    return 2 * i + 1;
}

int right(MaxHeap *maxHeap, int i) {
    return 2 * i + 2;
}

int parent(MaxHeap *maxHeap, int i) {
    return (i - 1) / 2;
}

/*访问堆顶元素*/
int peek(MaxHeap *maxHeap) {
    return maxHeap->data[0];
}

bool isEmpty(MaxHeap *maxHeap) {
    return maxHeap->size == 0;
}

void swap(MaxHeap *maxHeap, int i, int p) {
    int temp = maxHeap->data[i];
    maxHeap->data[i] = maxHeap->data[p];
    maxHeap->data[p] = temp;
}

/*元素入堆*/
void push(MaxHeap *maxHeap, int val) {
    if (maxHeap->size == MAX_CAPACITY) {
        printf("heap is full!");
        return;
    }
    maxHeap->data[maxHeap->size] = val;
    maxHeap->size++;
    
    siftUp(maxHeap, maxHeap->size - 1);
}

/*从节点 i 开始，从底至顶堆化*/
void siftUp(MaxHeap *maxHeap, int i) {
    while (true) {
        int p = parent(maxHeap, i);
        if (p < 0 || maxHeap->data[p] >= maxHeap->data[i]) {
            break;
        }
        swap(maxHeap, i, p);
        i = p;
    }
}

int pop(MaxHeap *maxHeap) {
    if (isEmpty(maxHeap)) {
        return INT64_MAX;
    }
    swap(maxHeap, 0, maxHeap->size-1);
    int val = maxHeap->data[maxHeap->size-1];
    maxHeap->size--;
    siftDown(maxHeap, 0);
    return val;
}

void siftDown(MaxHeap *maxHeap, int i) {
    while (true) {
        int l = left(maxHeap, i);
        int r = right(maxHeap, i);
        int max = i;
        if (l < maxHeap->size && maxHeap->data[max] < maxHeap->data[l]) {
            max = l;
        }
        if (r < maxHeap->size && maxHeap->data[max] < maxHeap->data[r]) {
            max = r;
        }
        if (max == i) {
            break;
        }
        swap(maxHeap, i, max);
        i = max;
    }
}
