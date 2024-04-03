#include "log.h"

void printIntArray(int *arr, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
    printf("}\n");
}
